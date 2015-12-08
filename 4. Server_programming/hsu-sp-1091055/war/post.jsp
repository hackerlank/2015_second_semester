   <%@page contentType="text/html;charset=utf-8" %>
   <%@page import = "java.util.* " %>
   <%@page import="com.google.appengine.api.datastore.*" %>
   <jsp:include page="header.jsp" />

    <div class="container">
    <%
    String post_id = request.getParameter("no");
    if (post_id == null) response.sendRedirect("/");
    DatastoreService datastore = DatastoreServiceFactory.getDatastoreService();
   	Query q = new Query("Posts")
   			.addFilter(Entity.KEY_RESERVED_PROPERTY, Query.FilterOperator.EQUAL,
   					KeyFactory.createKey("Posts",Long.parseLong(post_id)));
   	PreparedQuery pq = datastore.prepare(q);
   	Entity post = pq.asSingleEntity();
   	String id = (String)post.getProperty("id");
   	String title = (String)post.getProperty("title");
   	String content = (String)post.getProperty("content");
   	Date date = (Date) post.getProperty("date");
   	
    %>
    	<div class="post">
    		<h2><%=title %></h2>
    		<p><%= content %></p>
    		<p>작성자 :<%= id%></p>
    		<p>작성시간 :<%= date%></p>
    	</div><hr>
    <%
    	Query qc = new Query("Comments");
    	qc.addFilter("post_id", Query.FilterOperator.EQUAL, post_id);
    	PreparedQuery pqc = datastore.prepare(qc);
    	
    	for (Entity comment : pqc.asIterable()) {
    		String cmt_author = (String) comment.getProperty("cmt_author");
    		String cmt_content = (String) comment.getProperty("cmt_content");
    		Date cmt_date = (Date) comment.getProperty("cmt_date");
    %>
    	<div class="comment well">
    		<p><%=cmt_content %></p>
    		<p class="pull-right">by<%=cmt_author%> at <%=cmt_date%></p>
    	</div><hr>
   	<% 
    	}
   	%>

	<%
		String loginid = (String) session.getAttribute("loginid");
		if (loginid != null) { // 로그인상태에서만 댓글을 남길수 있음.
	%>
	<hr>
	<form role="form" action="process_cmt_write.jsp" method="post">
		<h4 class="form-write-heading">댓글 남기기</h4>
		<label>작성자 : <%=loginid%></label> <input type=hidden name=post_id
			value="<%=post_id%>" />
		<div class="controls controls-row">
			<textarea class="form-control" rows=2 name=content> </textarea>
		</div>
		<button class="btn btn-lg btn-primary" type="submit">댓글 작성</button>
	</form>
	<%
		} else {
	%>
	<hr>
	<div class="alert">
		<b>로그인</b> 하시면 댓글을 남기실수 있습니다. <a href="login.jsp"
			class="btn btn-small">로그인하기</a> 아이디가 없으시면 <b>가입</b>해주세요 <a
			href="register.jsp" class="btn btn-small">가입하기</a>
	</div>
	<% } %>

	<!-- <h1>First Blog</h1>
        <p class="lead">My First Article blah blah</p> -->
    </div><!-- /.container -->

  <jsp:include page="footer.jsp" />