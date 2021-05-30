#ifndef __TYPE__H__
#define __TYPE__H__

#include <stdint.h>
#include <stdbool.h>

#ifndef __I
#define __I     volatile const       /*!< Defines 'read only' permissions */
#endif  //!__I

#ifndef __O
#define __O     volatile             /*!< Defines 'write only' permissions */
#endif  //!__O

#ifndef __IO
#define __IO    volatile             /*!< Defines 'read / write' permissions */
#endif  //!__IO

/* following defines should be used for structure members */
#ifndef __IM
#define __IM     volatile const      /*! Defines 'read only' structure member permissions */
#endif  //!__IM

#ifndef __OM
#define __OM     volatile            /*! Defines 'write only' structure member permissions */
#endif  //!__OM

#ifndef __IOM
#define __IOM    volatile            /*! Defines 'read / write' structure member permissions */
#endif  //!__IOM

#endif  //!__TYPE__H__
