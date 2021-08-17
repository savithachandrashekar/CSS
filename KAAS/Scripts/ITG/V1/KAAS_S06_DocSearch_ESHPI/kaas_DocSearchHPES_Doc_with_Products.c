kaas_DocSearchHPES_Doc_with_Products()
{
	lr_save_string(lr_eval_string("{cp_WISEAccessToken}"), "WISEAccessToken");
	web_add_header("Content-Type","application/x-www-form-urlencoded");
	web_add_header("accessToken","{WISEAccessToken}");
	web_reg_find("Text={\"content\":{\"matches", "SaveCount=Text_count", LAST);
	
	lr_start_transaction("KAAS_T014_HPES_Doc_with_Products");
		
	web_custom_request("web_custom_request",
		"URL=https://hx9ekpvvbi.execute-api.us-east-1.amazonaws.com/KaaS-ITG/v2/search?q={p_DocWithProduct}&resultLimit=10&resultStart=0&countryCode={p_countryCode}&languageCode=en&disclosureLevel=696531864679532034919979251200881&printFields=documentID,title,documenttype,renderlink,matchscore,description,contentupdatedate,language,disclosurelevel,store,docsource,documenttypedetails,topics,categorizations&marginPercentage=65&store=docstore,manualstore,supportagentstore,manualagentstore,processagentstore,videostore,udp-content-default,sdlmanualstore&product={p_DocProductNumber}&cssMax=100&marginCssPercentage=23&compoundSearch=true&promotions=true",
		"Method=GET",
		"TargetFrame=",
		"Resource=0",
		"Referer=",
		"Body=",
		LAST);
	
	if (strcmp(lr_eval_string("{Text_count}"), "0") == 0)
	{
		lr_end_transaction("KAAS_T014_HPES_Doc_with_Products",LR_FAIL);
		return 0;
	}
	else
	{
		lr_end_transaction("KAAS_T014_HPES_Doc_with_Products",LR_PASS);
		return 0;
	}
	
//	return 0;
}
