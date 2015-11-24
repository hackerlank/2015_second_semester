<%@ page contentType = "text/html;charset=utf-8" %>
<%
	//세션의 무효화
	session.invalidate(); 
	//세션을 무효화하지 않고 다음과 같이 속성만 제거해도 된다. 
	//session.removeAttribute("MasterLoginID");
%>
	
<html>
	<head><title>로그아웃</title></head>
	<body>
		로그아웃하였습니다. <br/><br/>
		<a href = "login.html"> 처음부터 </a>
	</body>
</html>




