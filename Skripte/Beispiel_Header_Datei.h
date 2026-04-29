/**
 *****************************************************************************
 * @file
 * @brief      Product parameter file for MA01-455-1032 (MSA240T CO)
 *****************************************************************************/
#ifndef  MA01_455_1032_H
#define MA01_455_1032_H

/* Includes **************************************************************************************/
#include "System_config.h"

/* General configuration *************************************************************************/
#define SW_MATERIAL_NUMBER                        ("MA014541032A")
#define IDENT_A                                   (0x0000)

/*** ParseTool-Konfiguration **************************************************/
/* Automatically injected during release generation
   @SW_VERSION_H_DEFINE@
   @SW_VERSION_L_DEFINE@
 */

#define TOOL_NAME                                 "MA01_1032_MSA240T_CO_MP2"
/* Distinction of different devices in Paratool (15=ZuseG4(since 2024/06) 11=ZuseG4_256k; 7=ZuseF4_512k) */
#define TOOL_TYPE                                 15

#define MCU_NAME                                  "STM32G491RC"
#define MCU_PAGESIZE                              2048
#define MCU_APP_START_ADDR                        0x00009000
#define MCU_APP_END_ADDR                          0x0003FFFF
#define MCU_CPS_START_ADDR                        0x00009000
#define MCU_CPS_END_ADDR                          0x00009FFF
#define MCU_FT_START_ADDR                         0x00030000
#define MCU_FT_END_ADDR                           0x0003FFFF

#define PARSETOOL_DATA_ELEMENT_NAME               "cps_data"
#define PARSETOOL_EMPTY_ELEMENT_NAME              "empty"
#define PARSETOOL_VALIDFLAG_ELEMENT_NAME          "valid_flag"
#define PARSETOOL_CRC_ELEMENT_NAME                "crc"
#define PARSETOOL_A2L_IDENTIFIER                  "$$"
#define PARSETOOL_A2L_EXPERT_IDENTIFIER           "$$"
#define PARSETOOL_A2L_GROUP                       "Configuration"
#define PARSETOOL_A2L_STRUCTURE_TYPEDEF_ALIAS     "cps_data_t"
#define PARSETOOL_A2L_STRUCTURE_INSTANCE_ALIAS    "ZUSE"
#define PARSETOOL_STRUCTURE_TYPEDEF               "cps_data_t"
#define PARSETOOL_STRUCTURE_INSTANCE              "cps_data"
#define PARSETOOL_STRUCTURE_CONST_TYPEDEF         "const_cps_data_t"
#define PARSETOOL_STRUCTURE_CONST_INSTANCE        "const_cps_data"
#define PARSETOOL_STRUCTURE_CONST_INSTANCE_PREFIX "__SECTION_CPSDATA"
#define PARSETOOL_VALIDFLAG_CONTENT               0x5A5A5A5A
/* #define PARSETOOL_STRUCTURE_INSTANCE_PREFIX    "ATT_FAR_MEM" */
/* #define PARSETOOL_EMPTY_CONTENT                0             */
/* #define PARSETOOL_CRC_CONTENT                  0             */

/** Debug-Konfiguration ****************************************************************************/

/** @brief indication 0000-Module*/
#define OOOO_MODULE                            DISABLE_OPTION

/** @brief Activate rotary encoder */
#define ACTIVATE_ROTARY_ENCODER                DISABLE_OPTION

/** @brief Invert rotary encoder signal */
#define INVERT_ROTARY_ENCODER                  DISABLE_OPTION

/** @brief Activation of Most min max test */
#define ACTIVATE_MOST_MIN_MAX                  DISABLE_OPTION

/** @brief Activation of TVS Diod test */
#define ACTIVATE_TVS_DIOD_TEST                 DISABLE_OPTION

/** @brief Activation of task time monitoring */
#define ACTIVATE_SR_TASKS_TIMING_MONITOR       DISABLE_OPTION

/** @brief Activation of recording queue maximum fill level */
#define ACTIVATE_QUEUE_MAX_FILL_LEVEL_MONITOR  DISABLE_OPTION

/** @brief Activation of task time monitoring */
#define ACTIVATE_TOOL_DETECTION_TIMING_MONITOR DISABLE_OPTION

/** @brief Activation of error counter in Onewire and black channel (for EMV tests) */
#define DEBUG_COMMUNICATION_ERRORS             DISABLE_OPTION

/** @brief   Used for modelbased development */
#define MODELBASED_PLAYGROUND                  ENABLE_OPTION

/** @brief Activation of Vector VX1000 support */
#define ACTIVATE_VX1000                        DISABLE_OPTION

/** @brief Activation of floating motor stop test
 *  ToDo This compiler switch changes the behaviour of SR modules debug config should be moved to own sr config file ECZUSE-4370 */
#define ACTIVATE_FLOATING_MOTOR_STOP_TEST      DISABLE_OPTION

/** @brief Activate code to copy data from an old eeprom layout */
/* ToDo Copy of calibration data from old eeprom version to new version shall be disabled in future! */
#define COPY_CAL_DATA_V6_V8_TO_V10             DISABLE_OPTION

/*** Slave configuration ******************************************************/
/* Configure evaluation functions in master firmware for slave control*/

/** @brief Wheel drive selected mode selection */
#define DRIVE_MODE_SLAVE_SELECTION      DRIVE_MODE_SLAVE_NONE

/** @brief Activate module speed commad slave */
#define ACTIVATE_SPEED_CURVE_SLAVE      DISABLE_OPTION

/** Input Control configuration ***********************************************/

/** @brief Activation of safe soc wakeup */
#define ACTIVATE_SAFE_SOC_WAKEUP        DISABLE_OPTION

/**  Set speed input selection configuration */
/** @brief Selected mode selection */
#define SET_SPEED_SELECTION             SPEED_CURVE

/** @brief Enable poti-speed curve boost mode */
#define ACTIVATE_BOOST                  DISABLE_OPTION

/** @brief Enable individualization */
#define ACTIVATE_INDIVIDUALIZATION      DISABLE_OPTION

/** Mode selection configuration */
/** @brief ecomode module */
#define ACTIVATE_ECOMODE                DISABLE_OPTION

/** ecomode switch selection */
/** @brief use seperate switch instead of level_selection */
#if (ACTIVATE_ECOMODE == ENABLE_OPTION)
# define ECOMODE_SWITCH_AVAILABLE       DISABLE_OPTION
# if (ECOMODE_SWITCH_AVAILABLE == ENABLE_OPTION)
#  define ECOMODE_SWITCH                SR_Switches_NSR_3rd
# endif
#endif

/** @brief Enable autoboost module */
#define ACTIVATE_AUTOBOOST              DISABLE_OPTION

/** @brief Selected mode selection */
#define LEVEL_SELECTION_TYPE            LEVEL_SELECTION_NONE

#if (LEVEL_SELECTION_TYPE == LEVEL_SELECTION_3STEPS_ROLLING)
/** @brief Selected mode switch */
# define MODE_SWITCH                    MODE_SWITCH_NONE
#endif

/** Configure Level selection (Speed and Power curve presets */
/** @brief max configurable power curves presets */
#define POWER_CURVES_PRESETS_QUAN       1u

/** @brief max configurable speed curves presets */
#define SPEED_CURVES_PRESETS_QUAN       1u

/** @brief max configurable soft start curves presets */
#define SOFT_START_CURVES_PRESETS_QUAN  1u

/** HMI configuration *********************************************************/

/** @brief HMI display selection */
#define HMI_SELECTION                   HMI_MA01_MP

#if (HMI_SELECTION != HMI_NONE)

/** @brief Used Use an additional basic hmi (direct wired) with an onewire hmi */
# define ADDITIONAL_HMI_BASIC_AVAILABLE DISABLE_OPTION

/** @brief Level style  display selection req. ID : 660839
    There should be the option to switch between MODE_LEVEL_DISPLAY_APPEARENCE and STEP_LEVEL_DISPLAY_APPEARENCE
    Enabling this option is equivalent to MODE_LEVEL_DISPLAY_APPEARENCE */
# define DISPLAY_HIGHEST_LEVEL_LED_ONLY DISABLE_OPTION

/** @brief Activation of HMI_Data  */
# define HMI_PLUS_AVAILABLE             DISABLE_OPTION

# if ((HMI_SELECTION == HMI_BASIC) || (ADDITIONAL_HMI_BASIC_AVAILABLE == ENABLE_OPTION))
/** @brief Enables/disables illumination of temperature LED if neither level selection nor oil sensor is active */
#  define SHOW_TEMPERATURE_DERATING     DISABLE_OPTION
# endif

/** @brief Select if second HMI (Display) for wheel drive is available */
# define HMI_WHEEL_DRIVE_AVAILABLE      DISABLE_OPTION

# if (HMI_WHEEL_DRIVE_AVAILABLE == ENABLE_OPTION)
/** @brief Select installation orientation for second HMI */
#  define HMI_B_ORIENTATION             HMI_B_ORIENTATION_0_DEGREE
# endif
#endif

/*** Limitation ********************************************************************/

/** @brief [A] Reduction value for communicated battery current for high power accus */
/**        This value is necessary for securing the limits of the high power accus */
#define BATTERY_CURRENT_LIMIT_REDUCTION (4u)     /* ToDo: clarify ECZUSE-5084 */

/*** Monitoring ********************************************************************/

/** @brief [rpm] NSR speed threshold for switching from recuperative braking to fast braking (short circuit or floating).  */
/**        SR code detects stanstill at 500 rpm/min (electrical, with COMMUTATION_TIME_LIMIT = 320) */
#define SPEED_THRESHOLD_RECUPERATIVE_BRAKING      (700.0f)

/** @brief Activate motor NTC evaluation. Can by combined with motor temperature model evaluation. */
#define ACTIVATE_MOTOR_NTC                        ENABLE_OPTION

/** @brief NSR_FOURTH_SWITCH AVAILABLE is used only for ECJ3 for to use Motor Temperature as switch */
#define NSR_FOURTH_SWITCH_AVAILABLE               DISABLE_OPTION

/** @brief Activate motor temperature model evaluation. Can be combined with motor ntc. */
#define ACTIVATE_MOTOR_TEMPERATURE_MODEL          ENABLE_OPTION

/** @brief [A] Maximum motor phase current for motor temperature model evaluation. */
#define MAX_CURRENT_MOTOR_TEMP_MODELL             (120u)

/** @brief Configure current limiting by temperature                        */
#define CURRENT_LIMITING_DUE_TEMPERATURE          DISABLE_OPTION

/** @brief Configure cold start monitoring */
#define ACTIVATE_COLD_START_MONITORING            ENABLE_OPTION

/** @brief [mV] Voltage threshold for sleep */
#define TURN_OFF_UNDERVOLTAGE                     (22000u)

/** @brief Activation of rotation direction monitoring
    @attention This function should be only disabled for debug tests!
               If diasbled, dummy functions are included.                   */
#define ACTIVATE_ROTATION_MONITORING              ENABLE_OPTION

#if (ACTIVATE_ROTATION_MONITORING == ENABLE_OPTION)
/** @brief [degrees] Maximum inverse angle rotation */
# define MAX_INVERSE_ANGLE_ROTATION               (-538.6f)
#endif

/** @brief Activation of overspeed prevention. Only necessary if overspeed is near to desired speed and reaction time is small */
#define OVERSPEED_PREVENTION                      DISABLE_OPTION

/** @brief Activation of low speed monitoring
    @attention This function should be only disabled for debug tests!
               If diasbled, dummy functions are included.                   */
#define ACTIVATE_LOW_SPEED_MONITORING             ENABLE_OPTION

/** @brief Activation of blockade detection */
#define ACTIVATE_BLOCKADE_MONITORING              ENABLE_OPTION

/** @brief Configure Motortype */
#define USED_MOTOR_CONTROL             			  EC_MOTOR_CONTROL

/** @brief Activation of tool detection                                     */
#define ACTIVATE_TOOL_DETECTION                   DISABLE_OPTION

/** @brief Configure soft start speed ramp */
#define ACTIVATE_SOFT_START_SPEED_RAMP            ENABLE_OPTION

/** @brief Configure controlled speed ramp */
#define CONTROLLED_SPEED_RAMP_MODE                CONTROLLED_SPEED_RAMP_OFF

/** @brief   Curren time count feature
 *  @details If the features is enabled, the maximal drawn out current
 *           from the battery will be adjusted depending on the usage.
 *           Feature is only available for battery architectures with
 *           the #ADJUSTABLE_BATTERY_LIMIT feature enabled.
 */
#define CURRENT_TIME_COUNTER                      CURRENT_TIME_COUNTER_INTERPOLATION

/** @brief If this define is set, no operation with AR batteries is possible. */
#define AR_USAGE_PROHIBITED                       DISABLE_OPTION

/** @brief Activate hall sensor */
#define ACTIVATE_HALL_SENSOR                      DISABLE_OPTION

/** @brief Activate oil sensor */
#define ACTIVATE_OIL_SENSOR                       ENABLE_OPTION

/* Activate Virtual COM handler */
#if (BATTERY_COM_TYPE == BATTERY_COM_TYPE_NONE)
/** @brief   Selection of communication over debug interface
 *  @details Selects the debug interface type if virtual COM handler is enabled */
# define VIRTUAL_COM_HANDLER                      ENABLE_OPTION
# define VIRTUAL_COM_HANDLER_DEBUG_INTERFACE_TYPE INTERFACE_XCP
#else
# define VIRTUAL_COM_HANDLER                      DISABLE_OPTION
#endif

/* Activate external battery switching */
#define EXTERNAL_BATTERY_SWITCHING                DISABLE_OPTION

/** @brief Revert rotation direction after blockade */
#define ACTIVATE_HICKHACK                         DISABLE_OPTION

/*** PARAMETER for Paratool***********************************************************************/
/*
    < Restrictions for the parameter names >
      1) No paranthesis!
      2) No already used defines!
      3) The leading underscore character is used to distinguish between the defines and the variables.
         The ParseTool removes the underscore where unnecessary from version v2.0.2.0 on.

    < Allowed data types >
      (uint8_t), (int8_t), (uint16_t), (int16_t), (uint32_t), (int32_t), (uint64_t), (int64_t), (q15_t), (char), (float)

    < Description >
      A T T E N T I O N: The description text must contain no ";" !

    < Visibility >
      0 : Visible in expert mode
      1 : Visible in expert and normal mode

    Hints:
    1) Comments are possible and will be ignored by parser.
    2) Control characters of the parser are (maybe incomplete!)
 */  /***   *//*
 */  /**<   *//*
 */

/*      Parameter name                         Default value */  /**<  Nr      ; Data type   ;Lower limit ;Upper limit; Desciption                                                                                                                        ; Visibility   ; Variable name                              ; A2L Zusatz                                       */
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
#define XcpParNumCpsVersion                         (1u)         /**< xxx      ; (uint16_t)  ; 0          ; 65535     ; Parameterversion                                                                                                                  ; 2            ; cps_version ; DESCRIPTION = "CPS Version (Highbyte + Lowbyte)" */
#define CPS_MATERIALNUMMER_ASCII_Index              ('A')        /**< xxx      ; (char)      ;            ;           ; [Zeichen] CPS-Materialnummer Index                                                                                                ; 0            ; MATNr_Ascii[] */
#define CPS_MATERIALNUMMER_ASCII_BYTE1              ('2')        /**< xxx      ; (char)      ;            ;           ; [Zeichen] CPS-Materialnummer Byte 1                                                                                               ; 0            ; MATNr_Ascii[] */
#define CPS_MATERIALNUMMER_ASCII_BYTE2              ('3')        /**< xxx      ; (char)      ;            ;           ; [Zeichen] CPS-Materialnummer Byte 2                                                                                               ; 0            ; MATNr_Ascii[] */
#define CPS_MATERIALNUMMER_ASCII_BYTE3              ('0')        /**< xxx      ; (char)      ;            ;           ; [Zeichen] CPS-Materialnummer Byte 3                                                                                               ; 0            ; MATNr_Ascii[] */
#define CPS_MATERIALNUMMER_ASCII_BYTE4              ('1')        /**< xxx      ; (char)      ;            ;           ; [Zeichen] CPS-Materialnummer Byte 4                                                                                               ; 0            ; MATNr_Ascii[] */
#define CPS_MATERIALNUMMER_ASCII_BYTE5              ('5')        /**< xxx      ; (char)      ;            ;           ; [Zeichen] CPS-Materialnummer Byte 5                                                                                               ; 0            ; MATNr_Ascii[] */
#define CPS_MATERIALNUMMER_ASCII_BYTE6              ('5')        /**< xxx      ; (char)      ;            ;           ; [Zeichen] CPS-Materialnummer Byte 6                                                                                               ; 0            ; MATNr_Ascii[] */
#define CPS_MATERIALNUMMER_ASCII_BYTE7              ('4')        /**< xxx      ; (char)      ;            ;           ; [Zeichen] CPS-Materialnummer Byte 7                                                                                               ; 0            ; MATNr_Ascii[] */
#define CPS_MATERIALNUMMER_ASCII_BYTE8              ('1')        /**< xxx      ; (char)      ;            ;           ; [Zeichen] CPS-Materialnummer Byte 8                                                                                               ; 0            ; MATNr_Ascii[] */
#define CPS_MATERIALNUMMER_ASCII_BYTE9              ('0')        /**< xxx      ; (char)      ;            ;           ; [Zeichen] CPS-Materialnummer Byte 9                                                                                               ; 0            ; MATNr_Ascii[] */
#define CPS_MATERIALNUMMER_ASCII_KENNZIFFER_2       ('A')        /**< xxx      ; (char)      ;            ;           ; [Zeichen] CPS-Materialnummer Kennziffer 2                                                                                         ; 0            ; MATNr_Ascii[] */
#define CPS_MATERIALNUMMER_ASCII_KENNZIFFER_1       ('M')        /**< xxx      ; (char)      ;            ;           ; [Zeichen] CPS-Materialnummer Kennziffer 1                                                                                         ; 0            ; MATNr_Ascii[] */
#define XcpParNumGeraeteKennung2                    (29u)        /**< xxx      ; (uint8_t)   ; 0          ; 255       ; [ToolID2] ToolID2 des Geraets                                                                                                     ; 2            ; ToolID2 ; DESCRIPTION = "Tool-ID2 der Maschine" */
#define XcpParNumGeraeteKennung                     (255u)       /**< xxx      ; (uint8_t)   ; 0          ; 255       ; [ToolID] ToolID des Geraets                                                                                                       ; 2            ; ToolID ; DESCRIPTION = "Tool-ID der Maschine"  */
#define CPS_VARIANT_ID                              (0x0000u)    /**< xxx      ; (uint16_t)  ; 0          ; 65535     ; [VariantID] VariantID des Geraets                                                                                                 ; 0            ; VariantID */
#define CPS_MATNR_REV_L                             (0u)         /**< xxx      ; (uint8_t)   ; 0          ; 255       ; CPS-Materialnummer Revision Low Byte                                                                                              ; 0            ; Materialnumber_Rev[] */
#define CPS_MATNR_REV_H                             (0u)         /**< xxx      ; (uint8_t)   ; 0          ; 255       ; CPS-Materialnummer Revision High Byte                                                                                             ; 0            ; Materialnumber_Rev[] */

/* XCP Aktivierung */
#define CpsWrtXcpAktiv                              (1u)         /**< xxx      ; (uint16_t)  ; 0          ; 1         ; [boolean] (0 = Deactivation / 1 = Activation)                                                                                     ; 1            ; XcpAktiv */

/* Drehrichtung */
#define _CpsEsaFlgMotorDrehrichtungStufe01          (0u)         /**< xxx       ; (uint16_t)  ; 0         ; 1          ; [boolean] (0 = Rechtslauf, 1 = Linkslauf) Startdrehrichtung                                                                       ; 1            ; rotation_direction[] */

/* Potentiometerauswertung */
#define _CklSlfDutPotiX00                           (10u)        /**< xxx       ; (uint8_t)   ; 0         ; 100        ; [%] Poti Stopp Wert                                                                                                               ; 1            ; PotiDrzKennlinie_x[] */
#define _CklSlfDutPotiX01                           (12u)        /**< xxx       ; (uint8_t)   ; 0         ; 100        ; [%] Poti Start Wert                                                                                                               ; 1            ; PotiDrzKennlinie_x[] */
#define _CklSlfDutPotiX02                           (14u)        /**< xxx       ; (uint8_t)   ; 0         ; 100        ; [%] Stuetzstelle 2                                                                                                                ; 1            ; PotiDrzKennlinie_x[] */
#define _CklSlfDutPotiX03                           (16u)        /**< xxx       ; (uint8_t)   ; 0         ; 100        ; [%] Stuetzstelle 3                                                                                                                ; 1            ; PotiDrzKennlinie_x[] */
#define _CklSlfDutPotiX04                           (18u)        /**< xxx       ; (uint8_t)   ; 0         ; 100        ; [%] Stuetzstelle 4                                                                                                                ; 1            ; PotiDrzKennlinie_x[] */
#define _CklSlfDutPotiX05                           (20u)        /**< xxx       ; (uint8_t)   ; 0         ; 100        ; [%] Stuetzstelle 5                                                                                                                ; 1            ; PotiDrzKennlinie_x[] */
#define _CklSlfDutPotiX06                           (22u)        /**< xxx       ; (uint8_t)   ; 0         ; 100        ; [%] Stuetzstelle 6                                                                                                                ; 1            ; PotiDrzKennlinie_x[] */
#define _CklSlfDutPotiX07                           (26u)        /**< xxx       ; (uint8_t)   ; 0         ; 100        ; [%] Stuetzstelle 7                                                                                                                ; 1            ; PotiDrzKennlinie_x[] */
#define _CklSlfDutPotiX08                           (30u)        /**< xxx       ; (uint8_t)   ; 0         ; 100        ; [%] Stuetzstelle 8                                                                                                                ; 1            ; PotiDrzKennlinie_x[] */
#define _CklSlfDutPotiX09                           (34u)        /**< xxx       ; (uint8_t)   ; 0         ; 100        ; [%] Stuetzstelle 9                                                                                                                ; 1            ; PotiDrzKennlinie_x[] */
#define _CklSlfDutPotiX10                           (38u)        /**< xxx       ; (uint8_t)   ; 0         ; 100        ; [%] Stuetzstelle 10                                                                                                               ; 1            ; PotiDrzKennlinie_x[] */
#define _CklSlfDutPotiX11                           (42u)        /**< xxx       ; (uint8_t)   ; 0         ; 100        ; [%] Stuetzstelle 11                                                                                                               ; 1            ; PotiDrzKennlinie_x[] */
#define _CklSlfDutPotiX12                           (46u)        /**< xxx       ; (uint8_t)   ; 0         ; 100        ; [%] Stuetzstelle 12                                                                                                               ; 1            ; PotiDrzKennlinie_x[] */
#define _CklSlfDutPotiX13                           (50u)        /**< xxx       ; (uint8_t)   ; 0         ; 100        ; [%] Stuetzstelle 13                                                                                                               ; 1            ; PotiDrzKennlinie_x[] */
#define _CklSlfDutPotiX14                           (100u)       /**< xxx       ; (uint8_t)   ; 0         ; 100        ; [%] Deaktivierung Boost                                                                                                           ; 1            ; PotiDrzKennlinie_x[] */
#define _CklSlfDutPotiX15                           (100u)       /**< xxx       ; (uint8_t)   ; 0         ; 100        ; [%] Aktivierung Boost                                                                                                             ; 1            ; PotiDrzKennlinie_x[] */

#define _CklSlfDrzPotiStufe01Y00                    (3800u)      /**< xxx       ; (uint16_t)  ; 0         ; 28000      ; [1/min] Stoppdrehzahl                                                                                                             ; 1            ; PotiDrzKennlinie_0_y[] */
#define _CklSlfDrzPotiStufe01Y01                    (4250u)      /**< xxx       ; (uint16_t)  ; 0         ; 28000      ; [1/min] Startdrehzahl                                                                                                             ; 1            ; PotiDrzKennlinie_0_y[] */
#define _CklSlfDrzPotiStufe01Y02                    (4700u)      /**< xxx       ; (uint16_t)  ; 0         ; 28000      ; [1/min] Stuetzstelle 2                                                                                                            ; 1            ; PotiDrzKennlinie_0_y[] */
#define _CklSlfDrzPotiStufe01Y03                    (5150u)      /**< xxx       ; (uint16_t)  ; 0         ; 28000      ; [1/min] Stuetzstelle 3                                                                                                            ; 1            ; PotiDrzKennlinie_0_y[] */
#define _CklSlfDrzPotiStufe01Y04                    (5600u)      /**< xxx       ; (uint16_t)  ; 0         ; 28000      ; [1/min] Stuetzstelle 4                                                                                                            ; 1            ; PotiDrzKennlinie_0_y[] */
#define _CklSlfDrzPotiStufe01Y05                    (6050u)      /**< xxx       ; (uint16_t)  ; 0         ; 28000      ; [1/min] Stuetzstelle 5                                                                                                            ; 1            ; PotiDrzKennlinie_0_y[] */
#define _CklSlfDrzPotiStufe01Y06                    (6500u)      /**< xxx       ; (uint16_t)  ; 0         ; 28000      ; [1/min] Stuetzstelle 6                                                                                                            ; 1            ; PotiDrzKennlinie_0_y[] */
#define _CklSlfDrzPotiStufe01Y07                    (7400u)      /**< xxx       ; (uint16_t)  ; 0         ; 28000      ; [1/min] Stuetzstelle 7                                                                                                            ; 1            ; PotiDrzKennlinie_0_y[] */
#define _CklSlfDrzPotiStufe01Y08                    (8250u)      /**< xxx       ; (uint16_t)  ; 0         ; 28000      ; [1/min] Stuetzstelle 8                                                                                                            ; 1            ; PotiDrzKennlinie_0_y[] */
#define _CklSlfDrzPotiStufe01Y09                    (9100u)      /**< xxx       ; (uint16_t)  ; 0         ; 28000      ; [1/min] Stuetzstelle 9                                                                                                            ; 1            ; PotiDrzKennlinie_0_y[] */
#define _CklSlfDrzPotiStufe01Y10                    (9950u)      /**< xxx       ; (uint16_t)  ; 0         ; 28000      ; [1/min] Stuetzstelle 10                                                                                                           ; 1            ; PotiDrzKennlinie_0_y[] */
#define _CklSlfDrzPotiStufe01Y11                    (10800u)     /**< xxx       ; (uint16_t)  ; 0         ; 28000      ; [1/min] Stuetzstelle 11                                                                                                           ; 1            ; PotiDrzKennlinie_0_y[] */
#define _CklSlfDrzPotiStufe01Y12                    (11650u)     /**< xxx       ; (uint16_t)  ; 0         ; 28000      ; [1/min] Stuetzstelle 12                                                                                                           ; 1            ; PotiDrzKennlinie_0_y[] */
#define _CklSlfDrzPotiStufe01Y13                    (12610u)     /**< xxx       ; (uint16_t)  ; 0         ; 28000      ; [1/min] Stuetzstelle 13                                                                                                           ; 1            ; PotiDrzKennlinie_0_y[] */
#define _CklSlfDrzPotiStufe01Y14                    (12610u)     /**< xxx       ; (uint16_t)  ; 0         ; 28000      ; [1/min] Boostdrehzahl                                                                                                             ; 1            ; PotiDrzKennlinie_0_y[] */

/* Bremsparameter */
#define _CpsBrmStrBremseMotorMin                    (150u)       /**< xxx       ; (uint16_t)  ; 0          ; 300      ; [0,1A] Maximaler Motorphasenstrom beim aktiven Bremsen (=Akku laden)                                                              ; 1            ; BremseMaxMotorstrom */
#define _CpsBrmStrMindestAkkuBremsstrom             (5u)         /**< xxx       ; (uint16_t)  ; 5          ; 50       ; [0,1A] Mindestbremsstrom um den Zwischenkreis bei offenem 7.Mosfet nicht zu entladen                                              ; 0            ; MindestAkkuBremsstrom */
#define _CpsBrmStrAkkuRueckspeisen                  (50u)        /**< xxx       ; (uint16_t)  ; 5          ; 50       ; [0,1A] Maximaler Akkustrom beim aktiven Bremsen (=Akku laden)                                                                     ; 0            ; BremseMaxAkkustrom */
#define _CpsBrmZeiBremseVerzoegerung                (0u)         /**< xxx       ; (uint16_t)  ; 0          ; 65535    ; [ms] Nach dieser Zeit wird vom Freilauf in die aktive Bremse geschaltet                                                           ; 1            ; BremseZeitverzoegerung */
#define _CpsBrmZeiErrBremseMin                      (2600u)      /**< xxx       ; (uint16_t)  ; 0          ; 65535     ; [ms] Nach dieser Zeit wird der SR-Zustand Bremsen verlassen                                                                       ; 1            ; sr_min_brake_time */
#define _CpsBrmZeiErrBremseVerzoegerung             (1800u)      /**< xxx       ; (uint16_t)  ; 0          ; 65535     ; [ms] Nach dieser Zeit wird im SR-Zustand Bremsen die Kurzschlussbremse verzoegert eingelegt                                       ; 1            ; sr_short_circuit_brake_delay_time */
#define _CpsBrmStrAkkuRekupMeasureOffset            (0u)         /**< xxx       ; (uint16_t)  ; 0          ; 50       ; [0,1A] Offset Akkustrom beim aktiven Bremsen                                                                                      ; 1            ; BremseOffsetAkkustrom */

/* Drehzahlkontrolle */
#define _CpsGwuDrzZuNiedrigeDrehzahl                (3700u)      /**< xxx       ; (uint16_t)  ; 0          ; 9800      ; [rpm] Geforderte Mindestdrehzahl nach dem Anlauf, bei deren Unterschreitung abgeschaltet wird                                     ; 1            ; MinDrehzahlNormalbetrieb */
#define _CpsGwuZeiZuNiedrigeDrehzahl                (1000u)      /**< xxx       ; (uint16_t)  ; 0          ; 65535     ; [ms] Maximal erlaubte Dauer der Unterdrehzahl bevor Blockiererkennung ausloest                                                    ; 1            ; ZeitDrehzahlZuKlein */

/* Diagnosefaehigkeit */
#define _CpsLmgBinLeistungstyp                      (2u)         /**< xxx       ; (uint16_t)  ; 1          ; 2         ; [boolean] (1=ContPower/2=PeakPower) Indikator fuer eine Peak-, oder Continuous-Power Maschine                                     ; 1            ; ToolPowerIndicator */
#define _CpsLmgBinARDirektkontaktierung             (0u)         /**< xxx       ; (uint16_t)  ; 0          ; 1         ; [boolean] (0=Kontaktierung ueber Anschlussleitung / 1=Direktkontaktierung) Indikator fuer eine Direktkontaktierung des AR         ; 1            ; ToolARDirectConnection */
#define _CpsLmgBinCOM20Available                    (1u)         /**< xxx       ; (uint8_t)   ; 0          ; 1         ; [boolean] (0=COM 2.0 nicht verf??r/1=COM 2.0 verf??r) Indikator f??erf??rkeit der COM 2.0                                         ; 0            ; ToolCOM20Available */
#define _CpsDiaLeiKleinsterGeeigneterAkkuADG        (1100u)      /**< xxx       ; (uint16_t)  ; 1          ; 2500      ; [W] Leistungswert fuer den Abgleich "Akku nicht geeignet" durch das ADG2                                                          ; 1            ; ToolPowerValue */
#define _CpsDiaLeiGrundlastADG                      (280u)       /**< xxx       ; (uint16_t)  ; 1          ; 2500      ; [W] LL-Aufnahmeleistung der Maschine im 0x71 Command. Grundlast >110% fuehrt im ADG2 zu Fehler                                    ; 1            ; ToolInputPower                       ; UNIT = "W" */

/* Spannungsueberwachung */
#define _CpsGwuSpgEinschaltspannungZelle            (3150u)      /**< xxx       ; (uint16_t)  ; 2600       ; 4500      ; [mV] Zellspannung, (Leerlauf) ab der der Motor angesteuert werden darf                                                            ; 1            ; StartSpannungAkku */
#define _CpsGwuSpgUnterspannungZelle                (2700u)      /**< xxx       ; (uint16_t)  ; 2600       ; 4500      ; [mV] Unterhalb dieser Zellspannung wird Unterspannung erkannt und abgeschaltet                                                    ; 1            ; UnterspannungAkku */
#define _CpsGwuSpgUnterspannungZelleRuecksetzen     (2700u)      /**< xxx       ; (uint16_t)  ; 2600       ; 4500      ; [mV] Der Unterspannungszaehler wird oberhalb dieser Akku-Spannung zurueckgesetzt                                                  ; 1            ; undervoltage_slow_reset_threshold */
#define _CpsGwuZeiUnterspannungZelle                (2000u)      /**< xxx       ; (uint16_t)  ; 0          ; 65535     ; [ms] Zeit nach der der Unterspannungsfehler erkannt wird                                                                          ; 1            ; ZeitUnterspannungAkku */
#define _CpsGwuSpgUnterspannungTiefZelle            (2500u)      /**< xxx       ; (uint16_t)  ; 2500       ; 4500      ; [mV] Unterhalb dieser Zellspannung wird Unterspannung schnell erkannt und abgeschaltet                                            ; 0            ; UnterspannungAkkuSchnell */
#define _CpsGwuSpgUnterspannungZelleTiefRuecksetzen (2600u)      /**< xxx       ; (uint16_t)  ; 2500       ; 4500      ; [mV] Der UnterspannungszaehlerTief wird oberhalb dieser Akku-Spannung zurueckgesetzt                                              ; 1            ; undervoltage_fast_reset_threshold */
#define _CpsGwuZeiUnterspannungTiefZelle            (100u)       /**< xxx       ; (uint16_t)  ; 0          ; 65535     ; [ms] Zeit nach der der Tiefe_Unterspannungsfehler erkannt wird                                                                    ; 0            ; ZeitUnterspannungAkkuSchnell */
#define _CpsGwuSpgUeberspannung                     (44000.0f)   /**< xxx       ; (float)  ; 26400      ; 47800     ; [mV] Oberhalb dieser Akkuspannung wird ein Ueberspannungsfehler erkannt und abgeschaltet                                          ; 0            ; UeberspannungAkku */

/* Blockiererkennung */
#define _CpsBlkZeiBlockierungErkannt                (100u)       /**< xxx       ; (uint16_t)  ; 100        ; 65535     ; [ms] Dauer bis die Blockiererkennung eingeschaltet wird                                                                           ; 1            ; ZeitBlockierZaehlung */
#define _CpsBlkZeiBlockierungAbschalten             (1000u)      /**< xxx       ; (uint16_t)  ; 1          ; 65535     ; [ms] maximale Blockierzeit des Motors                                                                                             ; 1            ; ZeitBlockierAbschaltung */
#define _CpsBlkWrtBlockadeDekrementBetrieb          (3000u)      /**< xxx       ; (uint16_t)  ; 1          ; 65535     ; [ms] Dauer bis der aktuelle Blockierzaehler um "EINS" dekrementiert wird                                                          ; 1            ; ZeitBlockierzaehlerDekrementSchnell */
#define _CpsBlkWrtBlockadeDekrementStillstand       (4000u)      /**< xxx       ; (uint16_t)  ; 1          ; 65535     ; [ms] Dauer bis der aktuelle Blockierzaehler um "EINS" dekrementiert wird                                                          ; 1            ; ZeitBlockierzaehlerDekrementLangsam */
#define _CpsBlkWrtBlockadeStromReduktionAus         (0u)         /**< xxx       ; (uint16_t)  ; 0          ; 65535     ; [Bit] Anzahl Blockaden bei der Stromreduktion deaktiviert wird                                                                    ; 1            ; NrBlockStromReduktionAus */
#define _CpsBlkWrtBlockadeStromReduktionEin         (4u)         /**< xxx       ; (uint16_t)  ; 0          ; 65535     ; [Bit] Maximale Anzahl der erlaubten Blockaden, bis die Stromreduktion greift                                                      ; 1            ; NrBlockStromReduktionEin */
#define _CpsBlkWrtBlockadeMax                       (5u)         /**< xxx       ; (uint16_t)  ; 0          ; 65535     ; [Bit] Maximale Anzahl auf die der Blockierzaehler laufen kann                                                                     ; 1            ; NrBlockStromReduktionMax */
#define _CpsBlkZeiBlockierzeitHochrampen            (1000u)      /**< xxx       ; (uint32_t)  ; 0          ; 65535     ; [ms] Maximale Zeit im Ansteuerverfahren OPEN LOOP RAMPUP                                                                          ; 1            ; max_time_blockade_open_loop_rampup */

/* Maximaler Motorstrom */
#define _CpsBlkStrMotorReduzierterAnlauf            (351u)       /**< xxx       ; (uint16_t)  ; 1          ; 1200      ; [0,1A] Reduzierter maximaler Anlaufmotorstrom, wenn die Anzahl an Blockanden ueberschritten ist                                   ; 1            ; MaxMotorstromReduziert */
#define _CpsLmgStrMotorMax                          (1200u)      /**< xxx       ; (uint16_t)  ; 1          ; 1200      ; [0,1A] maximaler Motorstrom, waerend Anlauf                                                                                       ; 1            ; MaxMotorstromAnlauf */
#define _CpsAlfStrMotorStartverfahren               (120.0f)     /**< xxx       ; (float)     ; 1.0        ; 120.0      ; [A] Maximaler Motorstrom, Startansteuerverfahren                                                                                  ; 1            ; MaxMotorstromStart */
#define _CpsAlfStrMotorNachAnlauffunktion           (1200u)      /**< xxx       ; (uint16_t)  ; 1          ; 1200      ; [0,1A] Maximaler Motorstrom, nach der Anlaufzeit                                                                                  ; 1            ; MaxMotorstromDauer */

/* Anlaufleistung */
#define _CpsAlfLeiAnlauffunktionStufe0Min           (1100u)      /**< xxx       ; (uint16_t)  ; 0          ; 3000      ; Anlaufleistung                    - [W] (0 -> 2100) Anlaufleistung Stufe0 Min                                                     ; 1            ; AnlaufleistungMin0 */
#define _CpsAlfLeiAnlauffunktionStufe0Max           (2400u)      /**< xxx       ; (uint16_t)  ; 0          ; 3000      ; Anlaufleistung                    - [W] (0 -> 2100) Anlaufleistung Stufe0 Max                                                     ; 1            ; AnlaufleistungMax0 */
#define _CpsAlfZeiAnlauffunktionAus                 (2000u)      /**< xxx       ; (uint16_t)  ; 0          ; 65535     ; [ms] Zeit fuer deren Dauer die Anlaufleistung (und der Anlaufstrom) gilt.                                                         ; 1            ; AnlaufZeit */
#define _CpsAlfTmcAnlauffunktionAus                 (125)        /**< xxx       ; (int16_t)   ; 0          ; 200       ; [Grad C] Motortemperatur bei der die Anlaufleistung abgeschaltet wird                                                             ; 1            ; MaxMotorTempAnlaufLeistung           ; UNIT = "Grad C" */

/* Reduzierfunktion Akku */
#define _CpsRdzSpgReduzierungEinZelle               (2900u)      /**< xxx       ; (uint16_t)  ; 0          ; 4200      ; [mV] Zellspannung unter der eine Reduzierung stattfinden soll                                                                     ; 1            ; cell_voltage_reduction.on */
#define _CpsRdzZeiReduzierungEin                    (1000u)      /**< xxx       ; (uint16_t)  ; 0          ; 5000      ; [ms] Zeit fuer welche die Zellspannung kleiner sein muss, damit die Reduzierung eintritt                                          ; 1            ; cell_voltage_reduction.delay_on */
#define _CpsRdzSpgReduzierungAusZelle               (3500u)      /**< xxx       ; (uint16_t)  ; 0          ; 4200      ; [mV] Zellspannung ueber der die Reduzierung beendet wird (falls sie aktiv war)                                                    ; 1            ; cell_voltage_reduction.off */
#define _CpsRdzZeiReduzierungAus                    (2000u)      /**< xxx       ; (uint16_t)  ; 0          ; 5000      ; [ms] Zeit fuer welche die Zellspannung groesser sein muss, damit die Reduzierung beendet wird                                     ; 1            ; cell_voltage_reduction.delay_off */
#define _CpsRdzSpgDeltaLeistung                     (33u)        /**< xxx       ; (uint16_t)  ; 0          ; 100       ; [%] Prozentwert um den die Leistung reduziert wird                                                                                ; 1            ; cell_voltage_reduction.power_percent */
#define _CpsRdzSpgDeltaDrehzahl                     (20u)        /**< xxx       ; (uint16_t)  ; 0          ; 100       ; [%] Prozentwert um den die Drehzahl reduziert wird                                                                                ; 1            ; cell_voltage_reduction.speed_percent */
#define _CpsRdzSpgMotorStrom                        (706u)       /**< xxx       ; (uint16_t)  ; 0          ; 65535     ; [0,1A] Maximaler Motorstrom, bei aktiver Reduzierung                                                                              ; 1            ; cell_voltage_reduction.current */

/* Reduzierfunktion Motor Temperatur */
#define _CpsRdzTmcMotorEin                          (130)        /**< xxx       ; (int16_t)   ; 0          ; 32767     ; [Grad C] Motortemperatur ueber der eine Reduzierung stattfinden soll                                                              ; 1            ; motor_temp_reduction.on */
#define _CpsRdzTmcMotorAus                          (120)        /**< xxx       ; (int16_t)   ; 0          ; 32767     ; [Grad C] Motortemperatur unter der die Reduzierung beendet wird                                                                   ; 1            ; motor_temp_reduction.off */
#define _CpsRdzTmpMotDeltaLeistung                  (33u)        /**< xxx       ; (uint16_t)  ; 0          ; 100       ; [%] Prozentwert um den die Leistung reduziert wird                                                                                ; 1            ; motor_temp_reduction.power_percent */
#define _CpsRdzTmpMotDeltaDrehzahl                  (20u)        /**< xxx       ; (uint16_t)  ; 0          ; 100       ; [%] Prozentwert um den die Drehzahl reduziert wird                                                                                ; 1            ; motor_temp_reduction.speed_percent */
#define _CpsRdzTmpMotMotorStrom                     (706u)       /**< xxx       ; (uint16_t)  ; 0          ; 65535     ; [0,1A] Maximaler Motorstrom, bei aktiver Reduzierung                                                                              ; 1            ; motor_temp_reduction.current */

/* Reduzierfunktion Elektronik Temperatur */
#define _CpsRdzTmcElektronikEin                     (85)         /**< xxx       ; (int16_t)   ; 0          ; 32767     ; [Grad C] Elektroniktemperatur ueber der eine Reduzierung stattfinden soll                                                         ; 1            ; elo_temp_reduction.on */
#define _CpsRdzTmcElektronikAus                     (75)         /**< xxx       ; (int16_t)   ; 0          ; 32767     ; [Grad C] Elektroniktemperatur unter der die Reduzierung beendet wird                                                              ; 1            ; elo_temp_reduction.off */
#define _CpsRdzTmpEloDeltaLeistung                  (33u)        /**< xxx       ; (uint16_t)  ; 0          ; 100       ; [%] Prozentwert um den die Leistung reduziert wird                                                                                ; 1            ; elo_temp_reduction.power_percent */
#define _CpsRdzTmpEloDeltaDrehzahl                  (20u)        /**< xxx       ; (uint16_t)  ; 0          ; 100       ; [%] Prozentwert um den die Drehzahl reduziert wird                                                                                ; 1            ; elo_temp_reduction.speed_percent */
#define _CpsRdzTmpEloMotorStrom                     (706u)       /**< xxx       ; (uint16_t)  ; 0          ; 65535     ; [0,1A] Maximaler Motorstrom, bei aktiver Reduzierung                                                                              ; 1            ; elo_temp_reduction.current */

/* Elektroniktemperaturueberwachung */
#define _CpsGwuTmcMosfetEinschalten                 (85)         /**< xxx       ; (int16_t)   ; 1          ; 130       ; [Grad C] Unterhalb dieser Temperatur ist der Motorbetrieb wieder zulaessig                                                        ; 1            ; TemperaturMosfetStart                ; UNIT = "Grad C" */
#define _CpsGwuTmcMosfetAbschalten                  (94)         /**< xxx       ; (int16_t)   ; 1          ; 130       ; [Grad C] Ueber dieser Temperatur ist der Motorbetrieb nicht mehr zulaessig                                                        ; 1            ; TemperaturMosfetStop                 ; UNIT = "Grad C" */

/* Motortemperaturueberwachung */
#define _CpsGwuTmcMotorEinschalten                  (120)        /**< xxx       ; (int16_t)   ; 1          ; 250       ; [Grad C] Unterhalb dieser Temperatur ist der Motorbetrieb wieder zulaessig                                                        ; 1            ; TemperaturMotorStart                 ; UNIT = "Grad C" */
#define _CpsGwuTmcMotorAbschalten                   (140)        /**< xxx       ; (int16_t)   ; 1          ; 250       ; [Grad C] Ueber dieser Temperatur ist der Motorbetrieb nicht mehr zulaessig                                                        ; 1            ; TemperaturMotorStop                  ; UNIT = "Grad C" */

/* MOTOR Temperaturmodell */
#define _CpsTmoWrtTemperaturmodellC5                (0.0f)       /**< xxx       ; (float)     ; -3.4E38    ; 3.4E38    ; [Grad C] (-3.4E38 -> 3.4E38) Parameter C5 Toffset bei Initialisierung                                                             ; 1            ; TemperaturModellC5 */
#define _CpsTmoWrtTemperaturmodellC1Betrieb         (5.0e-6f)    /**< xxx       ; (float)     ; -3.4E38    ; 3.4E38    ; [Ohm] Parameter C1 Ohmische Leistung                                                                                              ; 1            ; TemperaturModellC1Betrieb */
#define _CpsTmoWrtTemperaturmodellC2Betrieb         (1.5e-6f)    /**< xxx       ; (float)     ; -3.4E38    ; 3.4E38    ; [W/rpm] Parameter C2 Reib Leistung                                                                                                ; 1            ; TemperaturModellC2Betrieb */
#define _CpsTmoWrtTemperaturmodellC3Betrieb         (0.0001f)    /**< xxx       ; (float)     ; -3.4E38    ; 3.4E38    ; [W/K] Parameter C3 Ableit Leistung                                                                                                ; 1            ; TemperaturModellC3Betrieb */
#define _CpsTmoWrtTemperaturmodellC4Betrieb         (2.5e-7f)    /**< xxx       ; (float)     ; -3.4E38    ; 3.4E38    ; [W/(K*rpm)] Parameter C4 Luefterkuehlung Leistung                                                                                 ; 1            ; TemperaturModellC4Betrieb */
#define _CpsTmoWrtTemperaturmodellC6Betrieb         (1.0f)       /**< xxx       ; (float)     ; 0.2        ; 2.0       ; [1] (0.2 -> 2.0) Faktor zur Anpassung der Sensortemperatur                                                                        ; 1            ; TemperaturModellC6Betrieb */
#define _CpsTmoWrtTemperaturmodellC7Betrieb         (0.0f)       /**< xxx       ; (float)     ; -100.0     ; 100.0     ; [Grad C] (-100.0 -> 100.0) Parameter C7 Temperaturoffset des Sensors                                                              ; 1            ; TemperaturModellC7Betrieb */
#define _CpsTmoWrtTemperaturmodellC1Stillstand      (0.0f)       /**< xxx       ; (float)     ; -3.4E38    ; 3.4E38    ; [Ohm] Parameter C1 Ohmische Leistung                                                                                              ; 1            ; TemperaturModellC1Stillstand */
#define _CpsTmoWrtTemperaturmodellC2Stillstand      (0.0f)       /**< xxx       ; (float)     ; -3.4E38    ; 3.4E38    ; [W/rpm] Parameter C2 Reib Leistung                                                                                                ; 1            ; TemperaturModellC2Stillstand */
#define _CpsTmoWrtTemperaturmodellC3Stillstand      (0.001f)     /**< xxx       ; (float)     ; -3.4E38    ; 3.4E38    ; [W/K] Parameter C3 Ableit Leistung                                                                                                ; 1            ; TemperaturModellC3Stillstand */
#define _CpsTmoWrtTemperaturmodellC4Stillstand      (0.0f)       /**< xxx       ; (float)     ; -3.4E38    ; 3.4E38    ; [W/(K*rpm)] Parameter C4 Luefterkuehlung Leistung                                                                                 ; 1            ; TemperaturModellC4Stillstand */
#define _CpsTmoWrtTemperaturmodellC6Stillstand      (1.0f)       /**< xxx       ; (float)     ; 0.2        ; 2.0       ; [1] (0.2 -> 100.0) Faktor zur Anpassung der Sensortemperatur                                                                      ; 1            ; TemperaturModellC6Stillstand */
#define _CpsTmoWrtTemperaturmodellC7Stillstand      (0.0f)       /**< xxx       ; (float)     ; -100.0     ; 100.0     ; [Grad C] (-100.0 -> 100.0) Parameter C7 Temperaturoffset des Sensors                                                              ; 1            ; TemperaturModellC7Stillstand */

/* Leistungskennlinien */
#define _CpsKlfLeiNominalKl01                       (1100u)      /**< xxx       ; (uint16_t)  ; 0          ; 3000      ; Leistungskennlinie                 - [W] (0 -> 2100) Nominalleistung Min                                                          ; 1            ; LeistungNominalKl01 */
#define _CpsKlfLeiNominalKl02                       (2300u)      /**< xxx       ; (uint16_t)  ; 0          ; 3000      ; Leistungskennlinie                 - [W] (0 -> 2100) Nominalleistung Max                                                          ; 1            ; LeistungNominalKl02 */

/* Gemeinsame x-Achse */
#define _CklKlfDrzMotorKl01X00                      (0u)         /**< xxx       ; (uint16_t)  ; 0          ; 28000     ; [rpm] Drehzahlpunkt 1                                                                                                             ; 1            ; DrzLeiKennlinie_0_x[] */
#define _CklKlfDrzMotorKl01X01                      (3000u)      /**< xxx       ; (uint16_t)  ; 0          ; 28000     ; [rpm] Drehzahlpunkt 2                                                                                                             ; 1            ; DrzLeiKennlinie_0_x[] */
#define _CklKlfDrzMotorKl01X02                      (6000u)      /**< xxx       ; (uint16_t)  ; 0          ; 28000     ; [rpm] Drehzahlpunkt 3                                                                                                             ; 1            ; DrzLeiKennlinie_0_x[] */
#define _CklKlfDrzMotorKl01X03                      (7000u)      /**< xxx       ; (uint16_t)  ; 0          ; 28000     ; [rpm] Drehzahlpunkt 4                                                                                                             ; 1            ; DrzLeiKennlinie_0_x[] */
#define _CklKlfDrzMotorKl01X04                      (8500u)      /**< xxx       ; (uint16_t)  ; 0          ; 28000     ; [rpm] Drehzahlpunkt 5                                                                                                             ; 1            ; DrzLeiKennlinie_0_x[] */
#define _CklKlfDrzMotorKl01X05                      (9000u)      /**< xxx       ; (uint16_t)  ; 0          ; 28000     ; [rpm] Drehzahlpunkt 6                                                                                                             ; 1            ; DrzLeiKennlinie_0_x[] */
#define _CklKlfDrzMotorKl01X06                      (9500u)      /**< xxx       ; (uint16_t)  ; 0          ; 28000     ; [rpm] Drehzahlpunkt 7                                                                                                             ; 1            ; DrzLeiKennlinie_0_x[] */
#define _CklKlfDrzMotorKl01X07                      (10000u)     /**< xxx       ; (uint16_t)  ; 0          ; 28000     ; [rpm] Drehzahlpunkt 8                                                                                                             ; 1            ; DrzLeiKennlinie_0_x[] */
#define _CklKlfDrzMotorKl01X08                      (10500u)     /**< xxx       ; (uint16_t)  ; 0          ; 28000     ; [rpm] Drehzahlpunkt 9                                                                                                             ; 1            ; DrzLeiKennlinie_0_x[] */
#define _CklKlfDrzMotorKl01X09                      (11000u)     /**< xxx       ; (uint16_t)  ; 0          ; 28000     ; [rpm] Drehzahlpunkt 10                                                                                                            ; 1            ; DrzLeiKennlinie_0_x[] */
#define _CklKlfDrzMotorKl01X10                      (11500u)     /**< xxx       ; (uint16_t)  ; 0          ; 28000     ; [rpm] Drehzahlpunkt 11                                                                                                            ; 1            ; DrzLeiKennlinie_0_x[] */
#define _CklKlfDrzMotorKl01X11                      (12500u)     /**< xxx       ; (uint16_t)  ; 0          ; 28000     ; [rpm] Drehzahlpunkt 12                                                                                                            ; 1            ; DrzLeiKennlinie_0_x[] */
/* Minimale Leistungskennlinie  */
#define _CklKlfLeiMotorKl01Y00                      (900u)       /**< xxx       ; (uint16_t)  ; 0          ; 2100      ; [W] Leistung der min Kennlinie 1                                                                                                  ; 1            ; DrzLeiKennlinie_0_y_min[]            ; UNIT = "W" */
#define _CklKlfLeiMotorKl01Y01                      (900u)       /**< xxx       ; (uint16_t)  ; 0          ; 2100      ; [W] Leistung der min Kennlinie 2                                                                                                  ; 1            ; DrzLeiKennlinie_0_y_min[] */
#define _CklKlfLeiMotorKl01Y02                      (1000u)      /**< xxx       ; (uint16_t)  ; 0          ; 2100      ; [W] Leistung der min Kennlinie 3                                                                                                  ; 1            ; DrzLeiKennlinie_0_y_min[] */
#define _CklKlfLeiMotorKl01Y03                      (1070u)      /**< xxx       ; (uint16_t)  ; 0          ; 2100      ; [W] Leistung der min Kennlinie 4                                                                                                  ; 1            ; DrzLeiKennlinie_0_y_min[] */
#define _CklKlfLeiMotorKl01Y04                      (1100u)      /**< xxx       ; (uint16_t)  ; 0          ; 2100      ; [W] Leistung der min Kennlinie 5                                                                                                  ; 1            ; DrzLeiKennlinie_0_y_min[] */
#define _CklKlfLeiMotorKl01Y05                      (1100u)      /**< xxx       ; (uint16_t)  ; 0          ; 2100      ; [W] Leistung der min Kennlinie 6                                                                                                  ; 1            ; DrzLeiKennlinie_0_y_min[] */
#define _CklKlfLeiMotorKl01Y06                      (1100u)      /**< xxx       ; (uint16_t)  ; 0          ; 2100      ; [W] Leistung der min Kennlinie 7                                                                                                  ; 1            ; DrzLeiKennlinie_0_y_min[] */
#define _CklKlfLeiMotorKl01Y07                      (1100u)      /**< xxx       ; (uint16_t)  ; 0          ; 2100      ; [W] Leistung der min Kennlinie 8                                                                                                  ; 1            ; DrzLeiKennlinie_0_y_min[] */
#define _CklKlfLeiMotorKl01Y08                      (1100u)      /**< xxx       ; (uint16_t)  ; 0          ; 2100      ; [W] Leistung der min Kennlinie 9                                                                                                  ; 1            ; DrzLeiKennlinie_0_y_min[] */
#define _CklKlfLeiMotorKl01Y09                      (1100u)      /**< xxx       ; (uint16_t)  ; 0          ; 2100      ; [W] Leistung der min Kennlinie 10                                                                                                 ; 1            ; DrzLeiKennlinie_0_y_min[] */
#define _CklKlfLeiMotorKl01Y10                      (1050u)      /**< xxx       ; (uint16_t)  ; 0          ; 2100      ; [W] Leistung der min Kennlinie 11                                                                                                 ; 1            ; DrzLeiKennlinie_0_y_min[] */
#define _CklKlfLeiMotorKl01Y11                      (1000u)      /**< xxx       ; (uint16_t)  ; 0          ; 2100      ; [W] Leistung der min Kennlinie 12                                                                                                 ; 1            ; DrzLeiKennlinie_0_y_min[] */
/* Maximale Leistungskennlinie  */
#define _CklKlfLeiMotorKl02Y00                      (900u)       /**< xxx       ; (uint16_t)  ; 0          ; 3000      ; [W] Leistung der max Kennlinie 1                                                                                                  ; 1            ; DrzLeiKennlinie_0_y_max[]            ; UNIT = "W" */
#define _CklKlfLeiMotorKl02Y01                      (900u)       /**< xxx       ; (uint16_t)  ; 0          ; 3000      ; [W] Leistung der max Kennlinie 2                                                                                                  ; 1            ; DrzLeiKennlinie_0_y_max[] */
#define _CklKlfLeiMotorKl02Y02                      (1600u)      /**< xxx       ; (uint16_t)  ; 0          ; 3000      ; [W] Leistung der max Kennlinie 3                                                                                                  ; 1            ; DrzLeiKennlinie_0_y_max[] */
#define _CklKlfLeiMotorKl02Y03                      (1800u)      /**< xxx       ; (uint16_t)  ; 0          ; 3000      ; [W] Leistung der max Kennlinie 4                                                                                                  ; 1            ; DrzLeiKennlinie_0_y_max[] */
#define _CklKlfLeiMotorKl02Y04                      (2050u)      /**< xxx       ; (uint16_t)  ; 0          ; 3000      ; [W] Leistung der max Kennlinie 5                                                                                                  ; 1            ; DrzLeiKennlinie_0_y_max[] */
#define _CklKlfLeiMotorKl02Y05                      (2130u)      /**< xxx       ; (uint16_t)  ; 0          ; 3000      ; [W] Leistung der max Kennlinie 6                                                                                                  ; 1            ; DrzLeiKennlinie_0_y_max[] */
#define _CklKlfLeiMotorKl02Y06                      (2170u)      /**< xxx       ; (uint16_t)  ; 0          ; 3000      ; [W] Leistung der max Kennlinie 7                                                                                                  ; 1            ; DrzLeiKennlinie_0_y_max[] */
#define _CklKlfLeiMotorKl02Y07                      (2190u)      /**< xxx       ; (uint16_t)  ; 0          ; 3000      ; [W] Leistung der max Kennlinie 8                                                                                                  ; 1            ; DrzLeiKennlinie_0_y_max[] */
#define _CklKlfLeiMotorKl02Y08                      (2210u)      /**< xxx       ; (uint16_t)  ; 0          ; 3000      ; [W] Leistung der max Kennlinie 9                                                                                                  ; 1            ; DrzLeiKennlinie_0_y_max[] */
#define _CklKlfLeiMotorKl02Y09                      (2180u)      /**< xxx       ; (uint16_t)  ; 0          ; 3000      ; [W] Leistung der max Kennlinie 10                                                                                                 ; 1            ; DrzLeiKennlinie_0_y_max[] */
#define _CklKlfLeiMotorKl02Y10                      (2100u)      /**< xxx       ; (uint16_t)  ; 0          ; 3000      ; [W] Leistung der max Kennlinie 11                                                                                                 ; 1            ; DrzLeiKennlinie_0_y_max[] */
#define _CklKlfLeiMotorKl02Y11                      (1000u)      /**< xxx       ; (uint16_t)  ; 0          ; 3000      ; [W] Leistung der max Kennlinie 12                                                                                                 ; 1            ; DrzLeiKennlinie_0_y_max[] */

/* Wert weiterhin fuer KOM notwendig */
#define _CpsKliLeiAbgabeMaxKl03                     (2400u)      /**< xxx       ; (uint16_t)  ; 0          ; 3000      ; [W] Dieser Wert wird aktuell nur fuer die Kommunikation verwendet                                                                 ; 1            ; MaxLeistungStarkeKennlinie           ; UNIT = "W" */

/* Gate Treiber Konfiguration */
/* Strom Konfiguration */
#define _CpsGateTreiberIPreEnable                   (1u)         /**< xxx       ; (uint8_t)   ; 0          ; 1         ;  I_PRE_EN 0=enabled, 1=disabled (Gate driver pre-charge mode enable)                                                              ; 0            ; GateTreiberPreAktiv           */
#define _CpsGateTreiberIPreSink                     (15u)        /**< xxx       ; (uint8_t)   ; 0          ; 15        ;  Bitmuster Strom PRE_SINK (Pre-charge sink current setting)                                                                       ; 0            ; GateTreiberPreSinkStrom       */
#define _CpsGateTreiberIPreSrc                      (15u)        /**< xxx       ; (uint8_t)   ; 0          ; 15        ;  Bitmuster Strom PRE_SRC (Pre-charge source current)                                                                              ; 0            ; GateTreiberPreSrcStrom        */
#define _CpsGateTreiberIlsSink                      (15u)        /**< xxx       ; (uint8_t)   ; 0          ; 15        ;  Bitmuster Strom ILS_SINK (Low-side sink current)                                                                                 ; 0            ; GateTreiberILSSinkStrom       */
#define _CpsGateTreiberIhsSink                      (15u)        /**< xxx       ; (uint8_t)   ; 0          ; 15        ;  Bitmuster Strom IHS_SINK (High-side sink current)                                                                                ; 0            ; GateTreiberIHSSinkStrom       */
#define _CpsGateTreiberIlsSrc                       (15u)        /**< xxx       ; (uint8_t)   ; 0          ; 15        ;  Bitmuster Strom ILS_SRC (Low-side source current)                                                                                ; 0            ; GateTreiberILSSrcStrom        */
#define _CpsGateTreiberIhsSrc                       (15u)        /**< xxx       ; (uint8_t)   ; 0          ; 15        ;  Bitmuster Strom IHS_SRC (High-side source current)                                                                               ; 0            ; GateTreiberIHSSrcStrom        */

/* Timing Konfiguration */
#define _CpsGateTreiberTDrive1                      (0u)         /**< xxx       ; (uint8_t)   ; 0          ; 255       ;  Bitmuster Zeit TDrive1 (value for high and low side. First turn on or pre-charge period)                                         ; 0            ; GateTreiberZeitTD1            */
#define _CpsGateTreiberTDrive2                      (20u)        /**< xxx       ; (uint8_t)   ; 0          ; 255       ;  Bitmuster Zeit TDrive2                                                                                                           ; 0            ; GateTreiberZeitTD2            */
#define _CpsGateTreiberTDrive3                      (1u)         /**< xxx       ; (uint8_t)   ; 0          ; 255       ;  Bitmuster Zeit TDrive3 (value for high and low side. First turn off or pre-discharge period)                                     ; 0            ; GateTreiberZeitTD3            */
#define _CpsGateTreiberTDrive4                      (10u)        /**< xxx       ; (uint8_t)   ; 0          ; 255       ;  Bitmuster Zeit TDrive4                                                                                                           ; 0            ; GateTreiberZeitTD4            */
#define _CpsGateTreiberDtFall                       (2u)         /**< xxx       ; (uint8_t)   ; 0          ; 149       ;  Bitmuster DT Fall-Zeit (Dead time fall of phase node voltage)                                                                    ; 0            ; GateTreiberZeitDTFallend      */
#define _CpsGateTreiberDtRise                       (3u)         /**< xxx       ; (uint8_t)   ; 0          ; 149       ;  Bitmuster DT Anstiegs-Zeit (Dead time rise of phase node voltage)                                                                ; 0            ; GateTreiberZeitDTSteigend     */
/* User ID*/
#define _CpsGateTreiberUserID                       (2u)         /**< xxx       ; (uint8_t)  ; 0           ; 15        ;  Bitmuster USER_ID                                                                                                          ; 0            ; GateTreiberUserID             */

/* Strom-Zeit-Zaehler */
#define _CpsSz1ZeiStromzaehlerInit                  (60u)        /**< xxx       ; (uint16_t)  ; 0          ; 65535     ; [s] Maximaler Wert des Zaehlers im Normalfall                                                                                     ; 1            ; CtcCounterMaxDefault */
#define _CpsSz1ZeiStromzaehlerInitBegrenzt          (20u)        /**< xxx       ; (uint16_t)  ; 0          ; 65535     ; [s] Maximaler Wert des Zaehlers bei Begrenzung                                                                                    ; 1            ; CtcCounterMaxLimited */
#define _CpsSz1LeiFaktorPeak                        (100u)       /**< xxx       ; (uint8_t)   ; 0          ; 100       ; [%] Faktor fuer eine Peak- bzw. Continuous-Power Maschine (0: Nur Continuous, 100 %: nur Peak)                                    ; 1            ; ToolPowerFactor */
#define _CpsSzzDutRdzDrzZwischenstufe               (0u)         /**< xxx       ; (uint8_t)   ; 0          ; 100       ; [%] Faktor zur Reduzierung der Drehzahl fuer die Zwischenstufe                                                                    ; 1            ; CtcSpeedReductionIntermediate */
#define _CpsSzzDutRdzDrzDauer                       (0u)         /**< xxx       ; (uint8_t)   ; 0          ; 100       ; [%] Faktor zur Reduzierung der Drehzahl fuer den Dauerbetrieb                                                                     ; 1            ; CtcSpeedReductionContinuous */
#define _CpsSz1LeiDutZwischenstufe                  (100u)       /**< xxx       ; (uint8_t)   ; 0          ; 100       ; [%] Faktor der verfuegbaren Leistung fuer die Zwischenstufe                                                                       ; 1            ; CtcPowerFactorIntermediate */
#define _CpsSz1LeiFaktorDauer                       (100u)       /**< xxx       ; (uint8_t)   ; 0          ; 100       ; [%] Faktor der verfuegbaren Leistung fuer den Dauerbetrieb                                                                        ; 1            ; CtcPowerFactorContinuous */
#define _CpsSz1AkkustromToleranz                    (2u)         /**< xxx       ; (uint8_t)   ; 0          ; 100       ; [A] Erwartete Genauigkeit der Akkustrommessung                                                                                    ; 1            ; CtcBatteryCurrentTolerance */
#define _CpsSz1SpgReferenz                          (300u)       /**< xxx       ; (uint16_t)  ; 50         ; 65535     ; [100mV] CTC COM1.0: Referenzspannung des Akkus                                                                                        ; 1          ; Ctc1BatteryVoltageReference */
#define _CpsSz2SpgGrenze                            (300u)       /**< xxx       ; (uint16_t)  ; 50         ; 65535     ; [100mV] CTC COM2.0: Referenzspannung des Akkus                                                                                        ; 1          ; Ctc2BatteryVoltageReference */
#define _CpsSz1ZaehlerMinX                          (0.0f)       /**< xxx       ; (float)     ; 0          ; 1         ; [1] Minimaler Wert des relativen Stroms                                                                                           ; 1            ; CtcCounterXMin */
#define _CpsSz1ZaehlerMaxX                          (1.0f)       /**< xxx       ; (float)     ; 0          ; 1         ; [1] Maximaler Wert des relativen Stroms                                                                                           ; 1            ; CtcCounterXMax */
#define _CpsSz1ZaehlerMinY                          (-1.0f)      /**< xxx       ; (float)     ; -1         ; 0         ; [s/s] Minimaler Wert des Zaehlerfaktors                                                                                           ; 1            ; CtcCounterYMin */
#define _CpsSz1ZaehlerMaxY                          (1.0f)       /**< xxx       ; (float)     ; 0          ; 1         ; [s/s] Maximaler Wert des Zaehlerfaktors                                                                                           ; 1            ; CtcCounterYMax */
#define _CpsSz1ZeiBegSchwelleZwischenstufeAn        (0u)         /**< xxx       ; (uint16_t)  ; 0          ; 65535     ; [s] CTC COM1.0: Zaehlerwert zum Aktivieren der Zwischenstufe                                                                      ; 1            ; Ctc1CounterLevelIntermediateThresholdActivate */
#define _CpsSz1ZeiBegSchwelleZwischenstufeAus       (20u)        /**< xxx       ; (uint16_t)  ; 0          ; 65535     ; [s] CTC COM1.0: Zaehlerwert zum Deaktivieren der Zwischenstufe                                                                    ; 1            ; Ctc1CounterLevelIntermediateThresholdDeactivate */
#define _CpsSz1ZeiBegSchwelleDauerAus               (3u)         /**< xxx       ; (uint16_t)  ; 0          ; 65535     ; [s] CTC COM1.0: Zaehlerwert zum Deaktivieren des Dauerbetriebs                                                                    ; 1            ; Ctc1CounterLevelContinuousThresholdDeactivate */
#define _CpsSz2ZeiBegSchwelleZwischenstufeAn        (2u)         /**< xxx       ; (uint16_t)  ; 0          ; 65535     ; [s] CTC COM2.0: Zaehlerwert zum Aktivieren der Zwischenstufe                                                                      ; 1            ; Ctc2CounterLevelIntermediateThresholdActivate */
#define _CpsSz2ZeiBegSchwelleZwischenstufeAus       (5u)         /**< xxx       ; (uint16_t)  ; 0          ; 65535     ; [s] CTC COM2.0: Zaehlerwert zum Deaktivieren der Zwischenstufe                                                                    ; 1            ; Ctc2CounterLevelIntermediateThresholdDeactivate */
#define _CpsSz2ZeiBegSchwelleDauerAus               (3u)         /**< xxx       ; (uint16_t)  ; 0          ; 65535     ; [s] CTC COM2.0: Zaehlerwert zum Deaktivieren des Dauerbetriebs                                                                    ; 1            ; Ctc2CounterLevelContinuousThresholdDeactivate */
#define _CpsSz2ZeiBevorzugt                         (6u)         /**< xxx       ; (uint16_t)  ; 0          ; 65535     ; [s] Vom Akku anzufordernder Maximaler Wert des Zaehlers                                                                           ; 1            ; CtcCounterMaxPreferred */
#define _CpsSz2Aktiv                                (1u)         /**< xxx       ; (uint8_t)   ; 0          ; 1         ; Parameter zur Aktivierung des CTC COM2.0 (0: Inaktiv, 1: Aktiv)                                                                   ; 1          ; Ctc2Enable */

/* Kaltanlauffunktion */
#define _CpsKltDutDeltaLeistungReduzierungFrozen    (50u)        /**< xxx       ; (uint8_t)   ; 0          ; 100       ; [%] Faktor zur Reduzierung der Leistung fuer einen Akku mit der Temperatur "frozen"                                               ; 1            ; CsmPowerReductionFrozen */
#define _CpsKltDutDeltaLeistungReduzierungCold      (33u)        /**< xxx       ; (uint8_t)   ; 0          ; 100       ; [%] Faktor zur Reduzierung der Leistung fuer einen Akku mit der Temperatur "cold"                                                 ; 1            ; CsmPowerReductionCold */
#define _CpsKltDutDeltaZeitReduzierungFrozen        (65000u)     /**< xxx       ; (uint16_t)  ; 0          ; 65535     ; [s] Maximale Dauer der Reduzierung fuer einen Akku mit der Temperatur "frozen"                                                    ; 1            ; CsmLimitDurationFrozen */
#define _CpsKltDutDeltaZeitReduzierungCold          (65000u)     /**< xxx       ; (uint16_t)  ; 0          ; 65535     ; [s] Maximale Dauer der Reduzierung fuer einen Akku mit der Temperatur "cold"                                                      ; 1            ; CsmLimitDurationCold */

/* Drehzahlrampen */
#define _CklRgnDrzBegrenzungRampeKlX01              (3800u)      /**< xxx       ; (uint16_t)  ; 0          ; 30000     ; [rpm] Sanftanlauf-Kennlinie 0 Drehzahlpunkt 1                                                                                     ; 1            ; SpeedRampSoftStartCurve_0_x[] */
#define _CklRgnDrzBegrenzungRampeKlX02              (6600u)      /**< xxx       ; (uint16_t)  ; 0          ; 30000     ; [rpm] Sanftanlauf-Kennlinie 0 Drehzahlpunkt 2                                                                                     ; 1            ; SpeedRampSoftStartCurve_0_x[] */
#define _CklRgnDrzBegrenzungRampeKlX03              (7300u)      /**< xxx       ; (uint16_t)  ; 0          ; 30000     ; [rpm] Sanftanlauf-Kennlinie 0 Drehzahlpunkt 3                                                                                     ; 1            ; SpeedRampSoftStartCurve_0_x[] */
#define _CklRgnDrzBegrenzungRampeKlX04              (8000u)      /**< xxx       ; (uint16_t)  ; 0          ; 30000     ; [rpm] Sanftanlauf-Kennlinie 0 Drehzahlpunkt 4                                                                                     ; 1            ; SpeedRampSoftStartCurve_0_x[] */
#define _CklRgnDrzBegrenzungRampeKlX05              (8700u)      /**< xxx       ; (uint16_t)  ; 0          ; 30000     ; [rpm] Sanftanlauf-Kennlinie 0 Drehzahlpunkt 5                                                                                     ; 1            ; SpeedRampSoftStartCurve_0_x[] */
#define _CklRgnDrzBegrenzungRampeKlX06              (9400u)      /**< xxx       ; (uint16_t)  ; 0          ; 30000     ; [rpm] Sanftanlauf-Kennlinie 0 Drehzahlpunkt 6                                                                                     ; 1            ; SpeedRampSoftStartCurve_0_x[] */
#define _CklRgnDrzBegrenzungRampeKlX07              (10100u)     /**< xxx       ; (uint16_t)  ; 0          ; 30000     ; [rpm] Sanftanlauf-Kennlinie 0 Drehzahlpunkt 7                                                                                     ; 1            ; SpeedRampSoftStartCurve_0_x[] */
#define _CklRgnDrzBegrenzungRampeKlX08              (12500u)     /**< xxx       ; (uint16_t)  ; 0          ; 30000     ; [rpm] Sanftanlauf-Kennlinie 0 Drehzahlpunkt 8                                                                                     ; 1            ; SpeedRampSoftStartCurve_0_x[] */
#define _CklKlfDrzRgnBegrenzungRampeKlY01           (60u)        /**< xxx       ; (uint16_t)  ; 0          ; 10000     ; [rpm/10ms] Sanftanlauf-Kennlinie 0 Rampenwert 1                                                                                   ; 1            ; SpeedRampSoftStartCurve_0_y[] */
#define _CklKlfDrzRgnBegrenzungRampeKlY02           (60u)        /**< xxx       ; (uint16_t)  ; 0          ; 10000     ; [rpm/10ms] Sanftanlauf-Kennlinie 0 Rampenwert 2                                                                                   ; 1            ; SpeedRampSoftStartCurve_0_y[] */
#define _CklKlfDrzRgnBegrenzungRampeKlY03           (100u)       /**< xxx       ; (uint16_t)  ; 0          ; 10000     ; [rpm/10ms] Sanftanlauf-Kennlinie 0 Rampenwert 3                                                                                   ; 1            ; SpeedRampSoftStartCurve_0_y[] */
#define _CklKlfDrzRgnBegrenzungRampeKlY04           (200u)       /**< xxx       ; (uint16_t)  ; 0          ; 10000     ; [rpm/10ms] Sanftanlauf-Kennlinie 0 Rampenwert 4                                                                                   ; 1            ; SpeedRampSoftStartCurve_0_y[] */
#define _CklKlfDrzRgnBegrenzungRampeKlY05           (1000u)      /**< xxx       ; (uint16_t)  ; 0          ; 10000     ; [rpm/10ms] Sanftanlauf-Kennlinie 0 Rampenwert 5                                                                                   ; 1            ; SpeedRampSoftStartCurve_0_y[] */
#define _CklKlfDrzRgnBegrenzungRampeKlY06           (1000u)      /**< xxx       ; (uint16_t)  ; 0          ; 10000     ; [rpm/10ms] Sanftanlauf-Kennlinie 0 Rampenwert 6                                                                                   ; 1            ; SpeedRampSoftStartCurve_0_y[] */
#define _CklKlfDrzRgnBegrenzungRampeKlY07           (1000u)      /**< xxx       ; (uint16_t)  ; 0          ; 10000     ; [rpm/10ms] Sanftanlauf-Kennlinie 0 Rampenwert 7                                                                                   ; 1            ; SpeedRampSoftStartCurve_0_y[] */
#define _CklKlfDrzRgnBegrenzungRampeKlY08           (1000u)      /**< xxx       ; (uint16_t)  ; 0          ; 10000     ; [rpm/10ms] Sanftanlauf-Kennlinie 0 Rampenwert 8                                                                                   ; 1            ; SpeedRampSoftStartCurve_0_y[] */

#define _CpsRgnWrtDrehzahlRampeFallend              (1600u)      /**< xxx       ; (uint16_t)  ; 1          ; 65535     ; Drehzahlregler                     - [rpm/10ms] (1 -> 65535) Schrittweite der fallenden Drehzahlrampe                             ; 1            ; DrehzahlRampeFallend */

/* Switch between control methods */
#define _CpsFluxWrtMinSpeed                         (1400.0f)    /**< xxx       ; (float)    ; 0          ; 3.4E38     ; [rpm] Minimum speed for flux observer                                                                          ; 0            ; min_speed_flux_observer */
#define _CpsSrpeWrtMaxSpeed                         (1700.0f)    /**< xxx       ; (float)    ; 0          ; 3.4E38     ; [rpm] Maximum speed for srpe method                                                                            ; 0            ; max_speed_srpe */
#define _CpsMcElTurnsChangeAccelerating             (2.0f)       /**< xxx       ; (float)    ; 0          ; 3.4E38     ; [rpm] Number of electrical turns before changing the control method while accelerating                         ; 0            ; el_turns_before_change_accelerating */
#define _CpsMcElTurnsChangeBraking                  (2.0f)       /**< xxx       ; (float)    ; 0          ; 3.4E38     ; [rpm] Number of electrical turns before changing the control method while braking                              ; 0            ; el_turns_before_change_braking */

/* Drehzahlregler Allgemein */
#define _CpsRgnWrtDrehzahlSkalierung                (4u)         /**< xxx       ; (uint16_t)  ; 0          ; 10        ; [%] Parameter zur Skalierung der soll und ist Drehzahl als Eingang fuer den Drehzahlregler                                        ; 0            ; Drehzahlregler_Skalierung_Drehzahl */

/* Drehzahlregler vor Umschaltung */
#define _CpsRgn1WrtDrehzahlKp                       (0.0128f)    /**< xxx       ; (float)     ; 0          ; 3.4E38    ; Drehzahlregler                    - [Nm/(rad/s)] Parameter Kp                                                                     ; 0            ; Drehzahlregler1.Kp */
#define _CpsRgn1WrtDrehzahlKi                       (0.0212f)    /**< xxx       ; (float)     ; 0          ; 3.4E38    ; Drehzahlregler                    - [Nm/((rad/s)*s)] Parameter Ki                                                                 ; 0            ; Drehzahlregler1.Ki */
#define _CpsRgn1WrtDrehzahlKa                       (1.65f)      /**< xxx       ; (float)     ; 0          ; 3.4E38    ; Drehzahlregler                    - [1/s] Parameter Ka (fuer Antiwindup)                                                          ; 0            ; Drehzahlregler1.Ka */

#define _CpsRgnWrtMomentRampeSteigend               (0.05f)      /**< xxx       ; (float)     ; 0          ; 3.4E38    ; Drehzahlregler - [Nm/ms] (1 -> 65535) Schrittweite der steigenden Momentenrampe                                                   ; 1            ; torque_ramp_up */
#define _CpsRgnWrtMomentRampeFallend                (0.2f)       /**< xxx       ; (float)     ; 0          ; 3.4E38    ; Drehzahlregler - [Nm/ms] (1 -> 65535) Schrittweite der fallenden Momentenrampe                                                    ; 1            ; torque_ramp_down */

#define _CpsRgiWrtStromRampeQSteigend               (20.0f)      /**< xxx       ; (float)     ; 0          ; 3.4E38     ; [A/ms] Schrittweite der steigenden SollStromrampe                                                                          ; 0            ; SollStromRampeQSteigend */
#define _CpsRgiWrtStromRampeQFallend                (20.0f)      /**< xxx       ; (float)     ; 0          ; 3.4E38     ; [A/ms] Schrittweite der fallenden SollStromrampe                                                                           ; 0            ; SollStromRampeQFallend */
#define _CpsRgiWrtStromRampeDSteigend               (80.0f)      /**< xxx       ; (float)      ; 0          ; 3.4E38    ; [A/ms] Schrittweite der steigenden SollStromrampe                                                                          ; 0            ; SollStromRampeDSteigend */
#define _CpsRgiWrtStromRampeDFallend                (20.0f)      /**< xxx       ; (float)      ; 0          ; 3.4E38    ; [A/ms] Schrittweite der fallenden SollStromrampe                                                                           ; 0            ; SollStromRampeDFallend */

#define _CpsRgnWrtAVGFilterFactor                   (4)          /**< xxx       ; (int16_t)   ; 1          ; 32767     ; Drehzahlregler - [] (1 -> 32767) Faktor zur Filterung der Drehzahlmesswerte                                                       ; 0            ; speed_avg_filter_factor */
#define _CpsRgpWrtAVGFilterFactor                   (1)          /**< xxx       ; (s16)       ; 1          ; 32767     ; Leistungsregler                       - [] (1 -> 32767) Faktor zur Filterung der Leistungsmesswerte; 0; power_avg_filter_factor */

/* Stromregler */
#define _CpsRgiWrtStromKp                           (0.03016f)   /**< xxx      ; (float)      ; 0          ; 3.4E38    ; Stromregler                       - [V/A]     Parameter Kp                                                                        ; 0            ; StromreglerMotor.Kp */
#define _CpsRgiWrtStromKi                           (37.6991f)   /**< xxx      ; (float)      ; 0          ; 3.4E38    ; Stromregler                       - [V/(A*s)] Parameter Ki                                                                        ; 0            ; StromreglerMotor.Ki */
#define _CpsRgiWrtStromKa                           (1250.00f)   /**< xxx      ; (float)      ; 0          ; 3.4E38    ; Stromregler                       - [1/s]     Parameter Ka (fuer Antiwindup)                                                      ; 0            ; StromreglerMotor.Ka */

#define _CpsRgiWrtStromKpFast                       (0.04021f)   /**< xxx      ; (float)      ; 0          ; 3.4E38    ; Stromregler                       - [V/A]     Parameter Kp                                                                        ; 0            ; StromreglerMotorFast.Kp */
#define _CpsRgiWrtStromKiFast                       (75.3982f)   /**< xxx      ; (float)      ; 0          ; 3.4E38    ; Stromregler                       - [V/(A*s)] Parameter Ki                                                                        ; 0            ; StromreglerMotorFast.Ki */
#define _CpsRgiWrtStromKaFast                       (1875.00f)   /**< xxx      ; (float)      ; 0          ; 3.4E38    ; Stromregler                       - [1/s]     Parameter Ka (fuer Antiwindup)                                                      ; 0            ; StromreglerMotorFast.Ka */

#define _CpsRgiWrtCurrentThresholdActivate          (20.0f)      /**< xxx      ; (float)      ; 0.0        ; 3.4E38    ; Stromregler                       - [A] (0 -> 3.4E38) Grenzwert zur Aktivierung des schnellen Stromreglers                        ; 0            ; CurrentDeltaActivate */
#define _CpsRgiWrtCurrentThresholdDeactivate        (0.0f)       /**< xxx      ; (float)      ; 0.0        ; 3.4E38    ; Stromregler                       - [A] (0 -> 3.4E38) Grenzwert zur Deaktivierung des schnellen Stromreglers                      ; 0            ; CurrentDeltaDeactivate */

#define _CpsRgiWrtEMFFactor                         (0.0f)       /**< xxx      ; (float)      ; 0.0        ; 3.4E38    ; Stromregler                       - [V/rpm] (0 -> 3.4E38) Faktor zur Berechnung der EMF-Spannung                                  ; 0            ; EMFFactor */
#define _CpsRgiWrtAVGFilterFactor                   (2)          /**< xxx      ; (int16_t)    ; 1          ; 32767     ; Stromregler                       - [] (1 -> 32767) Faktor zur Filterung der Strommesswerte                                       ; 0            ; AVGFilterFactor */

/* Adaptive overcurrent threshold */
#define _CpsAdaptOvercurrentRampe                   (200.0f)     /**< xxx      ; (float)      ; 0          ; 1000      ; [A/ms] Steigung der Rampe, mit welcher maximaler Sollstrom gerampt wird                                                          ; 0          ; AdaptOvercurRamp */
#define _CpsAdaptOvercurrentOffset                  (200.0f)     /**< xxx      ; (float)      ; 0          ; 1000      ; [A] Offset, welches auf den maximalen Sollstrom addiert wird um Uberstrom zu setzen                                              ; 0          ; AdaptOvercurOffset */

/* Leistungsregler Antreiben */
#define _CpsRgp1WrtLeistungSkalierung               (1u)         /**< xxx      ; (uint16_t)   ; 0          ; 10        ; Leistungsregler - [%] (0 -> 10) Parameter zur Skalierung der Soll- und IstLeistung als Eingang fuer den Leistungsregler           ; 0            ; Leistungsregler1_Skalierung_Leistung */
#define _CPS_UNUSED_1449                            (0u)         /**< xxx      ; (uint16_t)   ; 0          ; 0         ; Platzhalter fuer Allignement                                                                                                      ; 0            ; Unused_1449 */
#define _CpsRgp1WrtLeistungKp                       (0.00042f)   /**< xxx      ; (float)      ; 0          ; 3.4E38    ; Leistungsregler                     - [Nm/W]     Parameter Kp                                                                     ; 0            ; Leistungsregler1.Kp */
#define _CpsRgp1WrtLeistungKi                       (0.22f)      /**< xxx      ; (float)      ; 0          ; 3.4E38    ; Leistungsregler                     - [Nm/(W*s)] Parameter Ki                                                                     ; 0            ; Leistungsregler1.Ki */
#define _CpsRgp1WrtLeistungKa                       (533.3f)     /**< xxx      ; (float)      ; 0          ; 3.4E38    ; Leistungsregler                     - [1/s]     Parameter Ka (fuer Antiwindup)                                                    ; 0            ; Leistungsregler1.Ka */

/* Leistungsregler Bremsen */
#define _CpsRgp2WrtLeistungSkalierung               (2u)         /**< xxx      ; (uint16_t)   ; 0          ; 10        ; Leistungsregler  - [%] (0 -> 10) Parameter zur Skalierung der Soll- und IstLeistung als Eingang fuer den Leistungsregler          ; 0            ; Leistungsregler2_Skalierung_Leistung */
#define _CPS_UNUSED_1451                            (0u)         /**< xxx      ; (uint16_t)   ; 0          ; 0         ; Platzhalter fuer Allignement                                                                                                      ; 0            ; Unused_1451 */
#define _CpsRgp2WrtLeistungKp                       (0.0006f)    /**< xxx      ; (float)      ; 0          ; 3.4E38    ; Leistungsregler                     - [Nm/W]     Parameter Kp                                                                     ; 0            ; Leistungsregler2.Kp */
#define _CpsRgp2WrtLeistungKi                       (0.22f)      /**< xxx      ; (float)      ; 0          ; 3.4E38    ; Leistungsregler                     - [Nm/(W*s)] Parameter Ki                                                                     ; 0            ; Leistungsregler2.Ki */
#define _CpsRgp2WrtLeistungKa                       (366.67f)    /**< xxx      ; (float)      ; 0          ; 3.4E38    ; Leistungsregler                     - [1/s]     Parameter Ka (fuer Antiwindup)                                                    ; 0            ; Leistungsregler2.Ka */

/* Sensorloser Start SRPE */
#define _CpsSrpeWrtPositionDampingFactor            (3200.0f)    /**< xxx      ; (float)      ; 0.0        ; 3.4E38    ; FOC SRPE                         - [1/s]  Daempfungsfaktor des Winkels                                                            ; 0            ; position_damping_factor_srpe */
#define _CpsSrpeWrtVelocityDampingFactor            (4000000.0f) /**< xxx      ; (float)      ; 0          ; 3.4E38    ; FOC SRPE                         - [rad/s^2] Daempfungsfaktor der Drehzahl                                                        ; 0            ; velocity_damping_factor_srpe */
#define _CpsSrpeWrtActivateSpeedStartupReduction    (2700.0f)    /**< xxx      ; (float)      ; 0          ; 3.4E38    ; [rpm] Activation speed for startup reduction                                                                                      ; 0            ; activation_speed_startup_reduction */
#define _CpsSrpeWrtDeactivateSpeedStartupReduction  (3000.0f)    /**< xxx      ; (float)      ; 0          ; 3.4E38    ; [rpm] Deactivation speed for startup reduction                                                                                    ; 0            ; deactivation_speed_startup_reduction */

/* FOC Flussbeobachter */
#define _CpsFluxWrtVoltageStabilization             (432.0f)     /**< xxx      ; (float)     ; 0          ; 3.4E38    ; FOC Ansteuerung                   - [rad/s] Stabilisierungsspannung des Flussbeobachters                                            ; 0; voltage_stabilization_factor_flux */
#define _CpsFluxWrtVelocityDampingFactor            (3000000.0f) /**< xxx      ; (float)     ; 0          ; 3.4E38    ; FOC Ansteuerung                   - [rad/s^2] Daempfungsfaktor der Drehzahl im Flussbeobachter                                      ; 0; velocity_damping_factor_flux */
#define _CpsFluxWrtPositionDampingFactor            (2500.0f)    /**< xxx      ; (float)     ; 0          ; 3.4E38    ; FOC Ansteuerung                   - [1/s] Daempfungsfaktor des Winkels im FLussbeobachter                                            ; 0; position_damping_factor_flux */
#define _CpsFluxWrtCableResistance                  (0.002f)     /**< xxx      ; (float)     ; 0          ; 3.4E38    ; FOC Ansteuerung                   - [Ohm] Kabelwiderstand                                                                         ; 0            ; cable_resistance_flux        */

/* Oil sensor */
#define _CpsOlsDrzMinAuswertungAktiv                (1000u)      /**< xxx      ; (uint16_t)  ; 500       ; 1500      ; [1/min] Minimale Drehzahl, bei der die Auswertung des Ölsensorsignals aktiv ist                                                   ; 1          ; SensorOilRotationalSpeedMin */
#define _CpsOlsWrtZaehlerSteigend                   (100u)       /**< xxx      ; (uint16_t)  ; 0         ; 65535     ; [1] Schrittweite zur Erhöhung des Zählers, wenn der Sensor Öl erkennt (Entspricht Steigung mit [0,1/s])                           ; 1          ; SensorOilCounterStepUp */
#define _CpsOlsWrtZaehlerFallend                    (20u)        /**< xxx      ; (uint16_t)  ; 0         ; 65535     ; [1] Schrittweite zur Reduzierung des Zählers, wenn der Sensor kein Öl erkennt (Entspricht Steigung mit [0,1/s])                   ; 1          ; SensorOilCounterStepDown */
#define _CpsOlsWrtAnzeigeAus                        (5000u)      /**< xxx      ; (uint16_t)  ; 4750      ; 5500      ; [1] Grenze, bei der die LED ausgeschaltet wird                                                                                    ; 1          ; SensorOilCounterMinStatusPresent */

/* Einschlaf Parameter*/
#define _CpsStbZeiNormal                            (45000u)     /**< xxx      ; (uint32_t)  ; 1          ; 4000000   ; Einschlafzeit (LED an ohne gedrückte OPC)                                                                                  ; 1          ; sleep_time_standby */
#define _CpsStbZeiNebenverbrAktiv                   (120000u)    /**< xxx      ; (uint32_t)  ; 1          ; 4000000   ; Einschlafzeit (LED an ohne gedrückte OPC - Nebenverbraucher an)                                                            ; 1          ; sleep_time_standby_with_second_consumer */
#define _CpsEseZeiEinschlafen                       (600000u)    /**< xxx      ; (uint32_t)  ; 1          ; 4000000   ; Einschlafzeit (nach LED aus)                                                                                               ; 1          ; sleep_time */
#define _CpsEseZeiEinschlafenErr                    (30000u)     /**< xxx      ; (uint32_t)  ; 1          ; 4000000   ; Einschlafzeit bei sperrendem Fehler (nach LED aus)                                                                         ; 1          ; sleep_time_error */

#endif
