<%@ page contentType = "text/html;charset=utf-8" %>
<%
	String storedID = application.getInitParameter("MasterID");
	String storedPW = application.getInitParameter("MasterPassword");
	
	String id = request.getParameter("id");
	String pw = request.getParameter("pw");
	//id와 pw 모두 일치
	if(id.equals(storedID) && pw.equals(storedPW)) { 
		//로긴 성공을 나타내는 특정속성 설정
		session.setAttribute("MasterLoginID", id); 
%>
	
<html>
	<head><title>로그인 처리</title></head>
	<body>
		로그인에 성공했습니다. <br/><br/>
		<a href="loginCheck.jsp">로그인 체크</a>

	</body>
</html>

<%
	//id 일치 & pw 불일치
	} else if(id.equals(storedID)) { 
%>

<script>
	alert("패스워드가 다릅니다.");
	history.go(-1);
</script>

<%
	//id 불일치
	} else {
%>

<script>
	alert("로그인ID가 다릅니다.");
	history.go(-1);
</script>

<% 
	} 
%>




