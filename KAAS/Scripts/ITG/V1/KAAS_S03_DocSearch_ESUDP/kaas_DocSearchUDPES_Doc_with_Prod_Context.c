KAAS_T009_DocSearchUDPES_Doc_with_Prod_Context()
{
	
    
	lr_save_string(lr_eval_string("{cp_WISEAccessToken}"), "WISEAccessToken");
    web_add_header("Content-Type","application/x-www-form-urlencoded");
    web_add_header("accessToken","{WISEAccessToken}");
    
    //{"content":{"matches":[{"documentID":
    web_reg_find("Text=matches", "SaveCount=Text_count", LAST);
    
    
    lr_start_transaction("KAAS_T009_DocSearchUDPES_Doc_with_Prod_Context");
    web_custom_request("web_custom_request",
        "URL=https://hx9ekpvvbi.execute-api.us-east-1.amazonaws.com/KaaS-ITG/v2/search?q={p_DocwithProduct}&resultLimit=10&resultStart=0&regionCode={p_regionTMSID}&languageCode=en&disclosureLevel=696531864679532034919979251200881,47406819852170807613486806879990,218620138892645155286800249901443,287477763180518087286275037723076,887243771386204747508092376253257,600096605536507071488362545356335&printFields=documentID,title,documenttype,renderlink,matchscore,description,contentupdatedate,language,disclosurelevel,store,docsource,documenttypedetails,topics,categorizations&store=docstore,manualstore,supportagentstore,manualagentstore,processagentstore,videostore,udp-content-default,sdlmanualstore&product={p_docWithProdNumber}&aggregations=producttopics,documenttype,disclosurelevel,regionCode,topissue&compoundSearch=true",
        "Method=GET",
        "TargetFrame=",
        "Resource=0",
        "Referer=",
        "Body=",
        LAST);
    if (strcmp(lr_eval_string("{Text_count}"), "0") == 0)
	{
		lr_end_transaction("KAAS_T009_DocSearchUDPES_Doc_with_Prod_Context",LR_FAIL);
		
	}
	else
	{
		lr_end_transaction("KAAS_T009_DocSearchUDPES_Doc_with_Prod_Context",LR_PASS);
		
	}
	
    //lr_end_transaction("KAAS_T009_DocSearchUDPES_Doc_with_Prod_Context",LR_AUTO);
	return 0;
}
 