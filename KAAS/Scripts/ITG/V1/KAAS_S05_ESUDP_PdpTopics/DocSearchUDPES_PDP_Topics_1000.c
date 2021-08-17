DocSearchUDPES_PDP_Topics_1000()
{
	lr_save_string(lr_eval_string("{cp_WISEAccessToken}"), "WISEAccessToken");
	web_set_sockets_option("SSL_VERSION", "TLS1.2");
    web_add_header("Content-Type","application/x-www-form-urlencoded");
    web_add_header("accessToken","{WISEAccessToken}");
    
    
    web_reg_find("Text=\"matches\":[{\"documentID\"", "SaveCount=Text_count", LAST);
    lr_start_transaction("KAAS_T013_DocSearchUDPES_PDP_Topics_1000");
    
    web_custom_request("web_custom_request",
        "URL=https://hx9ekpvvbi.execute-api.us-east-1.amazonaws.com/KaaS-ITG/v2/search?q=*&resultLimit=800&resultStart=0&countryCode=162089707212699946554652&languageCode=en&disclosureLevel=696531864679532034919979251200881,47406819852170807613486806879990,218620138892645155286800249901443,287477763180518087286275037723076,887243771386204747508092376253257&printFields=documentID,title,documenttype,renderlink,matchscore,description,contentupdatedate,language,disclosurelevel,store,docsource,documenttypedetails,topics,filename,duration&topiccat={Pdp_TopicCat}&store=docstore,supportagentstore,udp-content-default&product={Pdp1000_productNum}",
        "Method=GET",
        "TargetFrame=",
        "Resource=0",
        "Referer=",
        "Body=",
        LAST);
    
     if(strcmp(lr_eval_string("{Text_count}"),"0")==0)
	{
		lr_end_transaction("KAAS_T013_DocSearchUDPES_PDP_Topics_1000", LR_FAIL);

	}
	else
	{
		lr_end_transaction("KAAS_T013_DocSearchUDPES_PDP_Topics_1000", LR_PASS);

	}
   // lr_end_transaction("KAAS_T013_DocSearchUDPES_PDP_Topics_1000",LR_AUTO);
	return 0;
}
