Login()
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

	web_submit_data("login", 
		"Action=https://jpetstore.cfapps.io/login", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=https://jpetstore.cfapps.io/login", 
		"Snapshot=t21.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=_csrf", "Value=67297f37-d478-4ea6-9bf7-c3618a5cc820", ENDITEM, 
		"Name=username", "Value=bilbo", ENDITEM, 
		"Name=password", "Value=youshallnotpass", ENDITEM, 
		EXTRARES, 
		"Url=/favicon.ico", "Referer=", ENDITEM, 
		LAST);

	lr_end_transaction("ManageLogin",LR_AUTO);

	lr_think_time(3);

	lr_start_transaction("SelectAnimals");

	web_reg_find("Text=JPetStore Demo", 
		LAST);

	web_url("sm_dogs.gif", 
		"URL=https://jpetstore.cfapps.io/catalog/categories/DOGS", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://jpetstore.cfapps.io/catalog", 
		"Snapshot=t22.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=/favicon.ico", "Referer=", ENDITEM, 
		LAST);

	web_reg_find("Text=JPetStore Demo", 
		LAST);

	web_url("K9-BD-01", 
		"URL=https://jpetstore.cfapps.io/catalog/products/K9-BD-01", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://jpetstore.cfapps.io/catalog/categories/DOGS", 
		"Snapshot=t23.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=/favicon.ico", "Referer=", ENDITEM, 
		LAST);

	web_reg_find("Text=JPetStore Demo", 
		LAST);

	web_url("Add to Cart", 
		"URL=https://jpetstore.cfapps.io/cart?add&itemId=EST-6", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://jpetstore.cfapps.io/catalog/products/K9-BD-01", 
		"Snapshot=t24.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=/favicon.ico", "Referer=", ENDITEM, 
		LAST);

	lr_end_transaction("SelectAnimals",LR_AUTO);

	lr_think_time(3);

	lr_start_transaction("ClickCheckOut");

	web_reg_find("Text=JPetStore Demo", 
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
		"Name=_csrf", "Value=82574183-bb9a-4ea3-bc50-910a7ee9e7ce", ENDITEM, 
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

	web_reg_find("Text=•Thank you, your order has been submitted.", 
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
		"Name=_csrf", "Value=82574183-bb9a-4ea3-bc50-910a7ee9e7ce", ENDITEM, 
		EXTRARES, 
		"Url=/favicon.ico", "Referer=", ENDITEM, 
		LAST);

	lr_end_transaction("Submit",LR_AUTO);

	lr_think_time(3);

	return 0;
}