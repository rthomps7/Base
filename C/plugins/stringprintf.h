#include <string>
#include <cstdarg>

std::string string_printf
  (
    const char * Format,
    ...
  )
  // does an sprintf of its remaining arguments according to Format,
  //returning the formatted result.
  {
    std::string Result;
    unsigned long TempBufSize = 128; // something reasonable to begin with
    while (true)
      {
        char *TempBuf = new char[TempBufSize];
        va_list Args;
        va_start(Args, Format);
        const long BufSizeNeeded = vsnprintf(TempBuf, TempBufSize, Format, Args);
          // not including trailing null
        va_end(Args);
        if (BufSizeNeeded >= 0 and BufSizeNeeded < TempBufSize)
          {
          // the whole thing did fit
            TempBufSize = BufSizeNeeded; // not including trailing null
            break;
          } //if
        free(TempBuf);
        if (BufSizeNeeded < 0)
          {
          // glibc < 2.1
            TempBufSize *= 2; // try something bigger
          }
        else
          {
          // glibc >= 2.1
            TempBufSize = BufSizeNeeded + 1;
              // now I know how much I need, including trailing null
          } //if
      } //while
    if (TempBuf != NULL)
      {
        Result.append(TempBuf, TempBufSize);
        delete[] TempBuf;
      } //if
    return
        Result;
  } //string_printf
