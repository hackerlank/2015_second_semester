<%@ page contentType = "text/html;charset=utf-8" %>
<%@ page import = "java.net.URLEncoder" %>
<%@ page import = "java.util.Date" %>
<%
	//name 및 date 쿠키 생성
	Cookie cookie = new Cookie("name", URLEncoder.encode("jsp 쿠키 테스트"));
	Cookie cookie2 = new Cookie("date", new Date().toString());
	
	response.addCookie(cookie);
	response.addCookie(cookie2);
%>

<html>
	<head><title>쿠키생성</title></head>
	<body>
		쿠키 이름 : <%= cookie.getName() %> <br/>
		쿠키  값  : <%= cookie.getValue() %> <br/>
		
		<p><a href="getCookies.jsp">Next page to view the cookie value</a>
	</body>
</html>




