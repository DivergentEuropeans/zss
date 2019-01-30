

/*
  This program and the accompanying materials are
  made available under the terms of the Eclipse Public License v2.0 which accompanies
  this distribution, and is available at https://www.eclipse.org/legal/epl-v20.html
  
  SPDX-License-Identifier: EPL-2.0
  
  Copyright Contributors to the Zowe Project.
*/

#ifndef ZIS_PARM_H_
#define ZIS_PARM_H_

#include "crossmemory.h"

#define RC_ZISPARM_OK                       0
#define RC_ZISPARM_MEMBER_NOT_FOUND         2
#define RC_ZISPARM_DDNAME_TOO_LONG          8
#define RC_ZISPARM_MEMBER_NAME_TOO_LONG     9
#define RC_ZISPARM_PARMLIB_ALLOC_FAILED     10
#define RC_ZISPARM_READ_BUFFER_ALLOC_FAILED 11
#define RC_ZISPARM_PARMLIB_READ_FAILED      12
#define RC_ZISPARM_PARMLIB_FREE_FAILED      13
#define RC_ZISPARM_NONZERO_VISITOR_RC       14
#define RC_ZISPARM_SLH_NOT_CREATED          15
#define RC_ZISPARM_SLH_ALLOC_FAILED         16
#define RC_ZISPARM_CMS_CALL_FAILED          17

#define ZIS_PARM_TEST_PARM_NAME   "TEST_ZIS_PARM"
#define ZIS_PARM_TEST_PARM_VALUE  "THIS VALUE MUST BE AVAILABLE IN ANY SERVICE"

#pragma map(zisMakeParmSet, "ZISMAKPS")
#pragma map(zisRemoveParmSet, "ZISREMPS")
#pragma map(zisReadParmlib, "ZISRDLIB")
#pragma map(zisPutParmValue, "ZISPUTPV")
#pragma map(zisGetParmValue, "ZISGETPV")
#pragma map(zisLoadParmsToServer, "ZISLOADP")

ZOWE_PRAGMA_PACK

typedef struct ZISParmSetEntry_tag {
  char eyecatcher[8];
#define ZIS_PARMSET_ENTRY_EYECATCHER  "RSZISPSE"
  struct ZISParmSetEntry_tag *next;
  const char *key;
  const char *value;
} ZISParmSetEntry;

typedef struct ZISParmSet_tag {
  char eyecatcher[8];
#define ZIS_PARMSET_EYECATCHER "RSZISPST"
  ShortLivedHeap *slh;
  ZISParmSetEntry *firstEntry;
} ZISParmSet;

typedef struct ZISParmStatus_tag {
  int internalRC;
  int internalRSN;
} ZISParmStatus;

ZOWE_PRAGMA_PACK_RESET

ZISParmSet *zisMakeParmSet();

void zisRemoveParmSet(ZISParmSet *parms);

int zisReadParmlib(ZISParmSet *parms, const char *ddname, const char *member,
                   ZISParmStatus *status);

int zisPutParmValue(ZISParmSet *parms, const char *name, const char *value);

const char *zisGetParmValue(const ZISParmSet *parms, const char *name);

int zisLoadParmsToServer(CrossMemoryServer *server, const ZISParmSet *parms,
                         int *reasonCode);

#endif /* ZIS_PARM_H_ */


/*
  This program and the accompanying materials are
  made available under the terms of the Eclipse Public License v2.0 which accompanies
  this distribution, and is available at https://www.eclipse.org/legal/epl-v20.html
  
  SPDX-License-Identifier: EPL-2.0
  
  Copyright Contributors to the Zowe Project.
*/
