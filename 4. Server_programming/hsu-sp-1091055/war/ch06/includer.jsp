<%@ page contentType="text/html;charset=utf-8" %>
<html>
	<head>
		<title>include 지시문</title>
	</head>
	<body>
		<% 
			String start = "[";
			String end = "]";
		%>
		현재의 날짜와 시각은
		<%@include file = "date.jspf" %>
		<br/>
		<span><%= jspf_var %></span>
	</body>
</html>