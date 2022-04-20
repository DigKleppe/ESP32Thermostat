/*
 * sensirionTask.h
 *
 *  Created on: Apr 18, 2022
 *      Author: dig
 */

#ifndef MAIN_INCLUDE_SENSIRIONTASK_H_
#define MAIN_INCLUDE_SENSIRIONTASK_H_


#define MEASINTERVAL			 	60  // interval for sensiron sensor in seconds

float getTemperature (void);

int getRTMeasValuesScript(char *pBuffer, int count) ;
int getNewMeasValuesScript(char *pBuffer, int count);
int getLogScript(char *pBuffer, int count);
void sensirionTask(void *pvParameter);


#endif /* MAIN_INCLUDE_SENSIRIONTASK_H_ */
