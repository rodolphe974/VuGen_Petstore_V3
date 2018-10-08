Checkout()
{	
	lr_start_transaction("ClickCheckOut");

	web_reg_find("Text=JPetStore Demo", 
		LAST);
	web_set_max_html_param_len("20000");
/*Correlation comment - Do not change!  Original value='82574183-bb9a-4ea3-bc50-910a7ee9e7ce' Name ='my_csrf_out' Type ='Manual'*/
	web_reg_save_param_ex(
		"ParamName=my_csrf_out",
		"LB=name=\"_csrf\" value=\"",
		"RB=\"",
		SEARCH_FILTERS,
		"Scope=Body",
		"RequestUrl=*/create*",
		LAST);

	web_url("Proceed to Checkout", 
		"URL=https://jpetstore.cfapps.io/my/orders/create?form", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://jpetstore.cfapps.io/cart", 
		"Snapshot=t25.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=/favicon.ico", "Referer=", ENDITEM, 
		LAST);

	lr_end_transaction("ClickCheckOut",LR_AUTO);

	lr_think_time(3);

	lr_start_transaction("FillInPaiement");

	web_reg_find("Text=JPetStore Demo", 
		LAST);

	web_reg_find("Text=Order", 
		LAST);

	web_submit_data("create", 
		"Action=https://jpetstore.cfapps.io/my/orders/create", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=https://jpetstore.cfapps.io/my/orders/create?form", 
		"Snapshot=t26.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=_csrf", "Value={my_csrf_out}", ENDITEM, 
		"Name=cardType", "Value=Visa", ENDITEM, 
		"Name=creditCard", "Value=5555", ENDITEM, 
		"Name=expiryDate", "Value=03/2020", ENDITEM, 
		"Name=billToFirstName", "Value=bilbo", ENDITEM, 
		"Name=billToLastName", "Value=baggins", ENDITEM, 
		"Name=billAddress1", "Value=5, proudfoot street", ENDITEM, 
		"Name=billAddress2", "Value=", ENDITEM, 
		"Name=billCity", "Value=Hobbitown", ENDITEM, 
		"Name=billState", "Value=TheShire", ENDITEM, 
		"Name=billZip", "Value=55555", ENDITEM, 
		"Name=billCountry", "Value=MiddleEarth", ENDITEM, 
		"Name=_shippingAddressRequired", "Value=on", ENDITEM, 
		"Name=continue", "Value=Continue", ENDITEM, 
		EXTRARES, 
		"Url=/favicon.ico", "Referer=", ENDITEM, 
		LAST);

	lr_end_transaction("FillInPaiement",LR_AUTO);

	lr_think_time(3);

	lr_start_transaction("Submit");

	web_reg_find("Text=JPetStore Demo", 
		LAST);

	web_reg_find("Text=Thank you, your order has been submitted.", 
		LAST);

	web_submit_data("create_2", 
		"Action=https://jpetstore.cfapps.io/my/orders/create", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=https://jpetstore.cfapps.io/my/orders/create", 
		"Snapshot=t27.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=_csrf", "Value={my_csrf_out}", ENDITEM, 
		EXTRARES, 
		"Url=/favicon.ico", "Referer=", ENDITEM, 
		LAST);

	lr_end_transaction("Submit",LR_AUTO);

	lr_think_time(3);

	return 0;
}