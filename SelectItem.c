SelectItem()
{
	lr_start_transaction("ClickItem");
	
		web_reg_find("Text=JPetStore Demo", 
			LAST);
	
		web_reg_find("Fail=NotFound",
		"Text={randItem}",
		LAST);
	
		web_url("ItemID",
			"URL=https://jpetstore.cfapps.io/catalog/items/{randItem}",
			"TargetFrame=",
			"Resource=0",
			"RecContentType=text/html",
			"Referer=https://jpetstore.cfapps.io/catalog/products/{randProduct}",
			"Snapshot=t16.inf",
			"Mode=HTML",
			EXTRARES,
			"URL=/favicon.ico", ENDITEM,
			LAST);
	
		lr_end_transaction("ClickItem",LR_AUTO);
	
		lr_think_time(3);
	return 0;
}
