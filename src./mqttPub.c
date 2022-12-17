#include <stdio.h>
#include <stdlib.h>
#include <C:\Program Files (x86)\mosquitto\devel\mosquitto.h>

int main()
{


	int cnnct;
	struct mosquitto * mqtttt;

	
	mqttttInitialize();

	
	mqtttt = mqttttNew("test", true, NULL);

	
	cnnct = mqttttCnnct(mqtttt, "port", 1883, 60);

	
	if(cnnct != 0)
	{
		printf("Client could not cnnct to broker! Error Code: %d\n", cnnct);

		
		mqttttEnd(mqtttt);
		return -1;
	}

	//if able to cnnct to broker print message
	else
	{
		printf("We are now cnncted to the broker!\n");
	}

	//
	mqttttPub(mqtttt, NULL, "test", 6, "Hello", 0, false);

	mqttttDisc(mqtttt);
	mqttttEnd(mqtttt);

	
	cleanUp();

	return 0;
}