#include <vector>
#include <SPI.h>
#include "ELM327Comm.h"
#include "SinkIterator.h"

static m3::ELM327Comm elm327;

void setup() {
	Serial.begin(115200);
	elm327.initialize_spi();
}


static std::string line;
void loop() {
	while(Serial.available()) {
		char c = Serial.read();
		if(c == '\r') {
			elm327.send_raw_command(line);
			line.clear();
			auto sink = [](char ch) { Serial.write(ch); };
			elm327.receive_command_response(m3::SinkIterator(std::ref(sink)));
		} else {
			line.push_back(c);
		}
	}
}
