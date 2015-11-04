package tes;

import java.io.IOException;

import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.google.appengine.api.blobstore.BlobKey;
import com.google.appengine.api.blobstore.BlobstoreService;
import com.google.appengine.api.blobstore.BlobstoreServiceFactory;
import com.google.appengine.api.datastore.DatastoreService;
import com.google.appengine.api.datastore.DatastoreServiceFactory;
import com.google.appengine.api.datastore.Entity;
import com.google.appengine.api.datastore.PreparedQuery;
import com.google.appengine.api.datastore.Query;

public class Serve extends HttpServlet{
	private BlobstoreService blobstoreService = BlobstoreServiceFactory.getBlobstoreService();
	
	@Override
	public void doGet(HttpServletRequest req, HttpServletResponse res) throws IOException {
		BlobKey blobKey = null;
		if(null == req.getParameter("blob-key")) {
			DatastoreService datastore = DatastoreServiceFactory.getDatastoreService();
			Query q = new Query("Image");
			PreparedQuery pq = datastore.prepare(q);
			for(Entity result : pq.asIterable()) {
				blobKey = new BlobKey((String) result.getProperty("key"));
				break;
			}
		} else {
			blobKey = new BlobKey(req.getParameter("blob-key"));
		}
		blobstoreService.serve(blobKey, res);
		
	}
}
