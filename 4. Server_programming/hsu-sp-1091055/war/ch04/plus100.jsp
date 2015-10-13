<%@ page contentType = "text/html;charset=utf-8" %>
<html>
	<head>
		<title>1부터 100까지의 합 구하기</title>
	</head>
	<body>
		<%
			int sum=0;
			for(int i=0 ; i<= 100 ; i++) {
				sum = sum+i;
			}
		%>
		1+2+3+...+99+100=<%= sum %>
	</body>
</html>