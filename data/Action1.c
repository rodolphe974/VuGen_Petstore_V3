Action1()
{

	web_set_sockets_option("SSL_VERSION", "TLS1.2");

	web_reg_find("Text=JPetStore Demo", 
		LAST);

	web_url("catalog", 
		"URL=https://jpetstore.cfapps.io/catalog", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t28.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=/favicon.ico", "Referer=", ENDITEM, 
		LAST);

	web_reg_find("Text=JPetStore Demo", 
		LAST);

	web_url("Sign In", 
		"URL=https://jpetstore.cfapps.io/login", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://jpetstore.cfapps.io/catalog", 
		"Snapshot=t29.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=/favicon.ico", "Referer=", ENDITEM, 
		LAST);

	web_reg_find("Text=JPetStore Demo", 
		LAST);

	web_submit_data("login", 
		"Action=https://jpetstore.cfapps.io/login", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=https://jpetstore.cfapps.io/login", 
		"Snapshot=t30.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=_csrf", "Value=b73f6534-f424-43b9-a4c2-a5f43b9ba439", ENDITEM, 
		"Name=username", "Value=bilbo", ENDITEM, 
		"Name=password", "Value=youshallnotpass", ENDITEM, 
		EXTRARES, 
		"Url=/favicon.ico", "Referer=", ENDITEM, 
		LAST);

	return 0;
}