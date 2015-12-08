   <%@page contentType="text/html;charset=utf-8" %>
   <%@page import="com.google.appengine.api.datastore.*" %>
   <%
   	DatastoreService datastore = DatastoreServiceFactory.getDatastoreService();
   	Entity user = new Entity("Users");
   	user.setProperty("id", request.getParameter("id"));
   	user.setProperty("password", request.getParameter("password").hashCode());
   	user.setProperty("email", request.getParameter("email"));
   	datastore.put(user);
   	
   	session.setAttribute("loginid", request.getParameter("id"));
   	response.sendRedirect("/");

   	%>