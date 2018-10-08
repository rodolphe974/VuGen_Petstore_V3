SelectAnimal()
{
	lr_start_transaction("ClickAnimal");

	web_reg_find("Text=JPetStore Demo", 
		LAST);

	web_reg_find("Text={Category}", 
		LAST);
	
	//web_reg_save_param_ex("ParamName=ProductID", "<a href=\"/catalog/products/","\">", LAST);

/*Correlation comment: Automatic rules - Do not change!  
Original value='FI-SW-01' 
Name ='ProductID' 
Type ='Manual'*/
	web_reg_save_param_ex(
		"ParamName=ProductID",
		"LB/IC=products/",
		"RB/IC=\">",
		"NotFound=warning",
		"Ordinal=all",
		SEARCH_FILTERS,
		"Scope=Body",
		"RequestUrl=*/{Category}*",
		LAST);
		
	web_url("Animal",
		"URL=https://jpetstore.cfapps.io/catalog/categories/{Category}",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=https://jpetstore.cfapps.io/catalog",
		"Snapshot=t14.inf",
		"Mode=HTML",
		EXTRARES,
		"URL=/favicon.ico", ENDITEM,
		LAST);

	lr_end_transaction("ClickAnimal",LR_AUTO);

	lr_think_time(3);
	return 0;
}
