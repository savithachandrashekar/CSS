kaas_DocSearchHPES_Doc_Categories()
{
	
	lr_save_string(lr_eval_string("{cp_WISEAccessToken}"), "WISEAccessToken");
	
	web_add_header("Content-Type","application/x-www-form-urlencoded");	
	web_add_header("accessToken","{WISEAccessToken}");
	
	web_reg_find("Text={\"content\":{\"matches", "SaveCount=Text_count", LAST);
	
	lr_start_transaction("KAAS_T015_DocSearchHPES_Doc_Categories");
	
	web_custom_request("web_custom_request",
		//"URL=https://hx9ekpvvbi.execute-api.us-east-1.amazonaws.com/KaaS-ITG/v2/search?q={p_DocCategories}&resultLimit=20&resultStart=0&languageCode=en&countryCode=us&store=tmsstore&filters=(class:(pm_series_value%5E1.5%20OR%20pm_name_value%20OR%20pm_number_value)%20AND%20contenttype:Product%20AND%20historicalwebsupportflag:(no)%20AND%20navigationpath:({p_HPES_Categories_Param2}))&clientId=WCC",
		"URL=https://hx9ekpvvbi.execute-api.us-east-1.amazonaws.com/KaaS-ITG/v2/search?q={p_DocCategories}&resultLimit=20&resultStart=0&languageCode=en&countryCode={p_countryCode}&store=docstore,manualstore,supportagentstore,manualagentstore,processagentstore,videostore,udp-content-default,sdlmanualstore&filters=(class:(pm_series_value%5E1.5%20OR%20pm_name_value%20OR%20pm_number_value)%20AND%20contenttype:Product%20AND%20historicalwebsupportflag:(no)%20AND%20navigationpath:({p_HPES_Categories_Param2}))&clientId=WCC,marginPercentage=65&cssMax=100&marginCssPercentage=23&compoundSearch=true&promotions=true",
		"Method=GET",
		"TargetFrame=",
		"Resource=0",
		"Referer=",
		"Body=",
		LAST);
	
	if (strcmp(lr_eval_string("{Text_count}"), "0") == 0)
	{
		lr_end_transaction("KAAS_T015_DocSearchHPES_Doc_Categories",LR_FAIL);
		return 0;
	}
	else
	{
		lr_end_transaction("KAAS_T015_DocSearchHPES_Doc_Categories",LR_PASS);
		return 0;
	}
	
//	lr_end_transaction("KAAS_T015_DocSearchHPES_Doc_Categories",LR_AUTO);
//	return 0;
}
