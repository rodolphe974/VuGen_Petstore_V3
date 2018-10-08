SelectProduct()
{
	/* Selection du produit */
	
	lr_start_transaction("ClickProduct");

	web_reg_find("Text=JPetStore Demo", 
		LAST);

	web_reg_find("Text={randProduct}", 
		LAST);

/*Correlation comment: Automatic rules - Do not change!  
Original value='EST-1' 
Name ='itemId' 
Type ='Manual'*/
	web_reg_save_param_ex(
		"ParamName=itemId",
		"LB/IC=items/",
		"RB/IC=\">",
		"Ordinal=all",
		SEARCH_FILTERS,
		"Scope=Body",
		"RequestUrl=*/{randProduct}*",
		LAST);

	web_url("ProductID",
		"URL=https://jpetstore.cfapps.io/catalog/products/{randProduct}",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=https://jpetstore.cfapps.io/catalog/categories/{Category}",
		"Snapshot=t15.inf",
		"Mode=HTML",
		EXTRARES,
		"URL=/favicon.ico", ENDITEM,
		LAST);

	lr_end_transaction("ClickProduct",LR_AUTO);
	
	lr_think_time(3);
	return 0;
}
