#ifndef MODULE_NAME_H
#define MODULE_NAME_H
 
#ifdef __cplusplus
extern "C" {
#endif
 
/* =============================================================================
* File:        module_name.h
* Author:      Your Name
* Created:     YYYY-MM-DD
* Description: Brief description of what this module does.
* ========================================================================= */
 
/* === Includes === */
#include <stdio.h>  // Only include what’s necessary
 
/* === Macro Definitions === */
#define MODULE_CONSTANT 42
 
/* === Type Definitions === */
typedef struct {
    int field1;
    float field2;
} ModuleStruct;
 
/* === Public Function Declarations === */
 
/**
* @brief Initializes the module.
*/
void Module_Init(void);
 
/**
* @brief Processes some logic.
*
* @param value A parameter description.
* @return Result of processing.
*/
int Module_Process(int value);
 
#ifdef __cplusplus
}
#endif
 
#endif /* MODULE_NAME_H */