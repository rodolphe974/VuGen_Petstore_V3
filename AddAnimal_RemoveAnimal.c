AddAnimal_RemoveAnimal()
{
	SelectAnimal();
	
	//pour selectionner un produit au hasard parmis la liste dispo sur la page accueil
	lr_save_string(lr_paramarr_random("ProductID"), "randProduct");
	SelectProduct();
	
	//pour selectionner un item au hasard parmis la liste dispo sur la page products
	//lr_save_string(lr_paramarr_random("itemId"), "randItem"); 
	//SelectItem();
	//ManageCart();
	
	//pour ajouter chaque item possible au panier 	
	for (compteur=1; compteur<=(lr_paramarr_len("itemId")); compteur++)
	{
		lr_save_string(lr_paramarr_idx("itemId",compteur), "randItem");
		SelectItem();
		AddCart();	
	}
	
	Checkout();

	return 0;
}