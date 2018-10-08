RemoveCart()
{
	lr_start_transaction("Remove");
	
		web_reg_find("Text=JPetStore Demo", 
			LAST);
	
	//pour compter le nombre de fois ou le texte est présent dans la page, sans retourner une erreur s'il n'est pas présent
		web_reg_find("SaveCount=empty_count",
		"Text=Your cart is empty.",
		LAST);
	
		web_url("Remove",
			"URL=https://jpetstore.cfapps.io/cart?remove&itemId={randItem}",
			"TargetFrame=",
			"Resource=0",
			"RecContentType=text/html",
			"Referer=https://jpetstore.cfapps.io/cart",
			"Snapshot=t18.inf",
			"Mode=HTML",
			EXTRARES,
			"URL=/favicon.ico", ENDITEM,
			LAST);
	
		lr_end_transaction("Remove",LR_AUTO);
	
		lr_think_time(3);
	return 0;
}
