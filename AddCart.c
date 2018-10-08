AddCart()
{
		lr_start_transaction("AddCart");
	
		web_reg_find("Text=JPetStore Demo", 
			LAST);
	
		web_reg_find("Text=Shopping Cart", 
			LAST);
	
		web_url("Add to Cart",
			"URL=https://jpetstore.cfapps.io/cart?add&itemId={randItem}",
			"TargetFrame=",
			"Resource=0",
			"RecContentType=text/html",
			"Referer=https://jpetstore.cfapps.io/catalog/items/{randItem}",
			"Snapshot=t17.inf",
			"Mode=HTML",
			EXTRARES,
			"URL=/favicon.ico", ENDITEM,
			LAST);
	
		lr_end_transaction("AddCart",LR_AUTO);
	
		lr_think_time(3);

	return 0;
}
