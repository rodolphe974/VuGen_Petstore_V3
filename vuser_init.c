vuser_init()
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
		"Snapshot=t19.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=/favicon.ico", "Referer=", ENDITEM, 
		LAST);

	lr_start_transaction("ClickSignIn");

	web_reg_find("Text=JPetStore Demo", 
		LAST);

/*Correlation comment - Do not change!  Original value='67297f37-d478-4ea6-9bf7-c3618a5cc820' Name ='my_csrf' Type ='Manual'*/
	web_reg_save_param_ex(
		"ParamName=my_csrf",
		"LB=name=\"_csrf\" value=\"",
		"RB=\"",
		SEARCH_FILTERS,
		"Scope=Body",
		"RequestUrl=*/login*",
		LAST);

	web_url("Sign In", 
		"URL=https://jpetstore.cfapps.io/login", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://jpetstore.cfapps.io/catalog", 
		"Snapshot=t20.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=/favicon.ico", "Referer=", ENDITEM, 
		LAST);

	lr_end_transaction("ClickSignIn",LR_AUTO);

	lr_think_time(3);

	lr_start_transaction("ManageLogin");

	web_reg_find("Text=JPetStore Demo", 
		LAST);
	web_reg_find("Text=Sign Out", 
		LAST);

	web_submit_data("login", 
		"Action=https://jpetstore.cfapps.io/login", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=https://jpetstore.cfapps.io/login", 
		"Snapshot=t21.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=_csrf", "Value={my_csrf}", ENDITEM, 
		"Name=username", "Value={Login}", ENDITEM, 
		"Name=password", "Value={Password}", ENDITEM, 
		EXTRARES, 
		"Url=/favicon.ico", "Referer=", ENDITEM, 
		LAST);

	lr_end_transaction("ManageLogin",LR_AUTO);

	lr_think_time(3);
	return 0;
}
