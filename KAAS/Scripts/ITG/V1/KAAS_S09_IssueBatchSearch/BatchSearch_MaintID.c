BatchSearch_MaintID()
{
	
	
	web_set_sockets_option("SSL_VERSION", "TLS1.2");
	
	lr_save_string(lr_eval_string("{cp_IssueBatchAccessToken}"), "IssueBatchAccessToken");
	web_add_header("accessToken","{IssueBatchAccessToken}");
	web_add_header("Content-Type","application/json");
		
	web_reg_find("Text=\"matches\":[{\"documentID\"", "SaveCount=Text_count", LAST);
	
	lr_start_transaction("KAAS_T020_IssueBatchSearch_MaintID");
	
	web_custom_request("web_custom_request",
		"URL=https://hx9ekpvvbi.execute-api.us-east-1.amazonaws.com/KaaS-ITG/v2/issueBatch/search",
		"Method=POST",
		"TargetFrame=",
		"Resource=0",
		"Referer=",
		"Body={    \"resultLimit\": 11,    \"printFields\": [        \"issuesignature\",        \"requiredtools\",        \"time\",        \"partnumber\",        \"skilllevel\",        \"title\",        \"description\",        \"contentupdatedate\"    ],    \"resultStart\": 0,    \"languageCode\": \"zhcn\",    \"requests\": [        {            \"issueSignature\": {                \"maintId\": \"{MaintID}\"            },            \"product\": [                \"22324083\"            ],            \"disclosureLevel\": [                \"696531864679532034919979251200881\",                \"47406819852170807613486806879990\",                \"218620138892645155286800249901443\",                \"287477763180518087286275037723076\",                \"887243771386204747508092376253257\"            ],            \"regionCode\": [                \"145557537553804145623571\",                \"145969036451726883647975\",                \"212299498967880112552079\"            ],            \"wildCard\": true        }    ]}",
		LAST);

	

	if(strcmp(lr_eval_string("{Text_count}"),"0")==0)
	{
		lr_end_transaction("KAAS_T020_IssueBatchSearch_MaintID", LR_FAIL);

	}
	else
	{
		lr_end_transaction("KAAS_T020_IssueBatchSearch_MaintID", LR_PASS);

	}
	//lr_end_transaction("KAAS_T020_IssueBatchSearch_MaintID", LR_AUTO);
	return 0;
}
