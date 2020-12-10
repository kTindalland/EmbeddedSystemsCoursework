![Unit Tests](https://github.com/kTindalland/EmbeddedSystemsCoursework/workflows/Unit%20Tests/badge.svg)
# Embedded Systems Coursework
## Team Members
* Kai Tindall
* Lincoln O'Connell

## Due date
6th of January 2021

## Scenario
The project is to create a smart thermostat controller. The device will contain a time of day clock and provide the following features and displays:

* Setting of current time and date

* Display of current temperature

* Display of current time and date

* Entry of a trigger temperature

* Output control for a heating circuit: When the temperature drops below the selected
trigger temperature for a given duration of time the heating control output will be turned on
and three short beeps are produced as confirmation. The given duration of time should be
adjustable from 0 to 90 seconds.

* When the temperature rises above the selected trigger temperature for a given
duration of time the heating control output will be turned off and 2 long beeps should be
produced as confirmation. The given duration of time should be adjustable from 0 to 60
seconds. Notes different duration of time should be allowed for turning on and turing off
the heating control output.

* The heating behavior should begin at 7:00 am in the morning and end at 10:30 pm.
Outside these time the heating control output will be turned off.
