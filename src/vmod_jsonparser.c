#include "config.h"

#include <stdio.h>
#include <stdlib.h>


#include "cache/cache.h"

#include "vtim.h"
#include "vcc_jsonparser_if.h"

#include "cJSON.h"

//dev
//make clean && ./configure && make && make check; less src/test-suite.log

const char* getJsonElementAsString(const char *name,const char *string ){
    cJSON *json = cJSON_Parse(string);
    cJSON *value = NULL;
    if (json == NULL)
    {
        const char *error_ptr = cJSON_GetErrorPtr();
        if (error_ptr != NULL)
        {
            fprintf(stderr, "Error before: %s\n", error_ptr);
        }
        cJSON_Delete(json);
        return NULL;
    }
    value = cJSON_GetObjectItemCaseSensitive(json, name);

    if (value == NULL )
    {
        printf("%s does not exist in parsed json",name);
        cJSON_Delete(json);
        return NULL;
    }

    if (cJSON_IsString(value) && (value->valuestring != NULL))
    {
        return value->valuestring;
    }

    cJSON_Delete(json);

    return NULL;
}


VCL_STRING
vmod_jsonParse(VRT_CTX, VCL_STRING key,  VCL_STRING jsonString)
{
	char *p;
	unsigned u, v;

	u = WS_Reserve(ctx->ws, 0); /* Reserve some work space */
	p = ctx->ws->f;		/* Front of workspace area */
	const char* parsedValue = getJsonElementAsString(key, jsonString);
	v = snprintf(p, u, parsedValue);

	v++;
	if (v > u) {
		/* No space, reset and leave */
		WS_Release(ctx->ws, 0);
		return (NULL);
	}
	/* Update work space with what we've used */
	WS_Release(ctx->ws, v);
	return (p);
}

