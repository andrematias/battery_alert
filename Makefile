CC = gcc

build:
	${CC} -Wall battery_alert.c -o battery_alert

clean:
	rm battery_alert
