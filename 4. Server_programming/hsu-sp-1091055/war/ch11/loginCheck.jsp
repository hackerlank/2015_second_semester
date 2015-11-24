<%@ page contentType = "text/html;charset=utf-8" %>
<%
	//세션의 MasterLoginID 속성 읽어옴
	String masterID = (String)session.getAttribute("MasterLoginID");
	boolean isLogin = false;
	
	//MasterLoginID에 값이 저장되어 있으면 로그인되어진 상태
	if(masterID != null) {
		isLogin = true;
	}
%>

<html>
	<head><title>로그인여부 검사</title></head>
	<body>
		<%
			if(isLogin) {
		%>
		아이디 "<%= masterID %>"로 로그인 한 상태 <br/><br/>
		<a href = "logout.jsp">로그아웃</a>
		<% 
			} else {
		%>
		로그인하지 않은 상태
		<%
			}
		%>
	</body>
</html>