import json
import wiotp.sdk.device
import time

myconfig = {
    "identify": {
        "orgId": "948e13",
        "typeId": "childSafety",
        "devicId": "731736810"
       
    },
    "auth": {
        "token": "SwoZoaA@ikppxUR9sG"
    }
}
clientwiotp.sdk.device.DeviceClient(config=myConfig, longHandlers=None)
client.connect()

while True:
        name="Smartbridge"
        #in area location

        #latitude=11.165198 
        #longitude=77.6037642

        #out are location

        latitude=11.165198
        longitude=77.6037642
        myData={'name':name,'lat':latitude,'lon':longitude}
        client.publishEvent(eventId="status",msgFormat="json",data=myData,qos=0, onPublish=None0)
        print("Data published to IoT platfrom:",myData)
        time.sleep(5)
client.disconnect()