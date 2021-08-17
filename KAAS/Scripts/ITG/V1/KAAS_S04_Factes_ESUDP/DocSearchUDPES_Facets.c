DocSearchUDPES_Facets()
{
	
    web_set_sockets_option("SSL_VERSION", "TLS1.2");
    web_add_header("Content-Type","application/x-www-form-urlencoded");
    lr_save_string(lr_eval_string("{cp_WISEAccessToken}"), "WISEAccessToken");
 	web_add_header("accessToken","{WISEAccessToken}");
    
 	//{"content":{"matches":[{"documentID"
 	web_reg_find("Text=\"matches\":[{\"documentID\"", "SaveCount=Text_count", LAST);
 	
 	lr_start_transaction("KAAS_T011_DocSearchUDPES_Facets");
 	
    web_custom_request("web_custom_request",
        "URL=https://hx9ekpvvbi.execute-api.us-east-1.amazonaws.com/KaaS-ITG/v2/search?q={p_facetSearch}&resultLimit=10&resultStart=0&countryCode=us&languageCode=en&disclosureLevel=696531864679532034919979251200881,47406819852170807613486806879990,218620138892645155286800249901443,287477763180518087286275037723076,887243771386204747508092376253257,600096605536507071488362545356335&printFields=documentID,title,documenttype,renderlink,matchscore,description,contentupdatedate,language,disclosurelevel,store,docsource,documenttypedetails,topics,categorizations&store=docstore,supportagentstore,manualagentstore,manualstore,videostore,processagentstore,udp-content-default&aggregations=producttopics,documenttype,disclosurelevel,countrycode,topissue&spellCheck=3&compoundSearch=true",
        "Method=GET",
        "TargetFrame=",
        "Resource=0",
        "Referer=",
        "Body=",
        LAST);
 	
 	if(strcmp(lr_eval_string("{Text_count}"),"0")==0)
	{
		lr_end_transaction("KAAS_T011_DocSearchUDPES_Facets", LR_FAIL);

	}
	else
	{
		lr_end_transaction("KAAS_T011_DocSearchUDPES_Facets", LR_PASS);

	}
	
    
   // lr_end_transaction("KAAS_T011_DocSearchUDPES_Facets",LR_AUTO);
	return 0;
}
