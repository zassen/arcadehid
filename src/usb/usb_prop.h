/**
  ******************************************************************************
  * @file    usb_prop.h
  * @author  MCD Application Team
  * @version V4.0.0
  * @date    21-January-2013
  * @brief   All processing related to Joystick Mouse demo
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2013 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software 
  * distributed under the License is distributed on an "AS IS" BASIS, 
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */


/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __USB_PROP_H
#define __USB_PROP_H

/* Includes ------------------------------------------------------------------*/
/* Exported types ------------------------------------------------------------*/
typedef enum _HID_REQUESTS
{
  GET_REPORT = 1,
  GET_IDLE,
  GET_PROTOCOL,

  SET_REPORT = 9,
  SET_IDLE,
  SET_PROTOCOL
} HID_REQUESTS;

typedef struct
{
  uint32_t bitrate;
  uint8_t format;
  uint8_t paritytype;
  uint8_t datatype;
}LINE_CODING;

/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
void ARC_init(void);
void ARC_Reset(void);
void ARC_SetConfiguration(void);
void ARC_SetDeviceAddress (void);
void ARC_Status_In (void);
void ARC_Status_Out (void);
RESULT ARC_Data_Setup(uint8_t);
RESULT ARC_NoData_Setup(uint8_t);
RESULT ARC_Get_Interface_Setting(uint8_t Interface, uint8_t AlternateSetting);
uint8_t *ARC_GetDeviceDescriptor(uint16_t );
uint8_t *ARC_GetConfigDescriptor(uint16_t);
uint8_t *ARC_GetStringDescriptor(uint16_t);
RESULT ARC_SetProtocol(void);
uint8_t *ARC_GetProtocolValue(uint16_t Length);
uint8_t *ARC_GetKBReportDescriptor(uint16_t Length);
uint8_t *ARC_GetMouseReportDescriptor(uint16_t Length);
uint8_t *ARC_GetHIDDescriptor(uint16_t Length);
uint8_t *ARC_VCP_GetLineCoding(uint16_t Length);
uint8_t *ARC_VCP_SetLineCoding(uint16_t Length);

/* Exported define -----------------------------------------------------------*/
#define ARC_GetConfiguration          NOP_Process
//#define ARC_SetConfiguration          NOP_Process
#define ARC_GetInterface              NOP_Process
#define ARC_SetInterface              NOP_Process
#define ARC_GetStatus                 NOP_Process
#define ARC_ClearFeature              NOP_Process
#define ARC_SetEndPointFeature        NOP_Process
#define ARC_SetDeviceFeature          NOP_Process
//#define ARC_SetDeviceAddress          NOP_Process

#define REPORT_DESCRIPTOR                  0x22

#define SEND_ENCAPSULATED_COMMAND   0x00
#define GET_ENCAPSULATED_RESPONSE   0x01
#define SET_COMM_FEATURE            0x02
#define GET_COMM_FEATURE            0x03
#define CLEAR_COMM_FEATURE          0x04
#define SET_LINE_CODING             0x20
#define GET_LINE_CODING             0x21
#define SET_CONTROL_LINE_STATE      0x22
#define SEND_BREAK                  0x23



#endif /* __USB_PROP_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
