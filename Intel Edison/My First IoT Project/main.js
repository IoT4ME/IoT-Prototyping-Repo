"use strict";
var cylon = require("cylon");
cylon.robot({
  name: "doorbot",
  connections: {
    edison: { adaptor: "intel-iot" }
  },
  devices: {
// digital sensors
    button: { driver: "button",        pin: 2, connection: "edison" },
    led:    { driver: "led",           pin: 3, connection: "edison" },
    led1:   { driver: "led",           pin: 4, connection: "edison" },
// i2c devices
screen: { driver: "jhd1313m1", connection: "edison" }
  },
writeMessage: function(message, color) {
var that = this;
var str = message.toString();
while (str.length < 16) {
      str = str + " ";
    }
console.log(message);
that.screen.setCursor(0,0);
that.screen.write(str);
switch(color)
    {
case "red":
that.screen.setColor(255, 0, 0);
break;
case "green":
that.screen.setColor(0, 255, 0);
break;
case "blue":
that.screen.setColor(0, 0, 255);
break;
default:
that.screen.setColor(255, 255, 255);
break;
    }
  },
reset: function() {
this.writeMessage("Lights System");
this.led.turnOff();
this.led1.turnOn();
  },
work: function() {
var that = this;
that.reset();
that.button.on('push', function() {
that.led.turnOn();
that.led1.turnOff();
that.writeMessage("Light ON", "blue");
    });
that.button.on('release', function() {
that.writeMessage("Light OFF", "green");
that.reset();
    });
  }
}).start();