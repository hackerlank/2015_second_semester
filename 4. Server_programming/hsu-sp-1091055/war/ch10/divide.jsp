<!-- for 500ERROR -->
<%@ page contentType = "text/html;charset=utf-8" %>
<%
	int num1 = Integer.parseInt(request.getParameter("num1"));
	int num2 = Integer.parseInt(request.getParameter("num2"));
%>
	
<html>
	<head><title>나누기 처리</title></head>
	<body>
		<%=num1 %> / <%=num2 %> = <%= (double)num1 / (double)num2 %> <br/>
		<a href="divide_form.html">back</a>
	</body>
</html>