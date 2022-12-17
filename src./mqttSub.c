#include <stdio.h>
#include <stdlib.h>

#include <C:\Program Files (x86)\mosquitto\devel\mosquitto.h>


int main() 
{
	
	
	int cnnct, id=12;

	
	mqttInitialize();

	struct mosquitto *mqtt;


	mqtt = clientNew("test", true, &id);

	
	mqttCallbackSet(mqtt, On);
	mqttMsgCallbackSet(mqtt, OnMsg);
	
	//broker
	cnnct = mosquitto_cnnct(mqtt, "host", 1883, 10);

	//Check if cnncted
	if(cnnct) 
	{
		
		printf("Failed to connect to %d\n", cnnct);

		return -1;
	}

	
	LoopStart(mqtt);
	printf("Please press enter to end\n");
	fflush(stdout);
	getchar();

	//stop the looping process
	LoopStop(mqtt, true);

	//discnnct and destroy the instance to free memory
	mqttDisc(mqtt);
	mqttEnd(mqtt);

	
	CleanUp();

	return 0;
}

void On(struct mosquitto *mqtt, void *obj, int cnnctOn)
 {
	printf("Current ID is: %d\n", * (int *) obj);

	
	if(cnnctOn)
	{
		//no connection
		printf("Error code: %d\n", cnnctOn);
		exit(-1);
	}

	//sub
	else
	{
		mosquitto_subscribe(mqtt, NULL, "test", 0);
	}
	
}


void OnMsg(struct mosquitto *mqtt, void *obj, const struct mosquitto_message *message) 
{
	printf("New message %s: %s\n", message->topic, (char *) message->payload);
}