   <%@page contentType="text/html;charset=utf-8" %>
   <%@page import="com.google.appengine.api.datastore.*" %>
   <%
   	request.setCharacterEncoding("utf-8");
   String id = (String)session.getAttribute("loginid");
   String title = request.getParameter("title");
   String content = request.getParameter("content");
   if((title=="") || (content=="")) {response.sendRedirect("/"); return; }
   
   
   	
   	
   	
   	DatastoreService datastore = DatastoreServiceFactory.getDatastoreService();
   	Entity user = new Entity("Posts");
   	user.setProperty("id", id);
   	user.setProperty("title", title);
   	user.setProperty("content", content);
   	user.setProperty("date", new java.util.Date());
   	
   	datastore.put(user);

   	response.sendRedirect("/");

   	%>