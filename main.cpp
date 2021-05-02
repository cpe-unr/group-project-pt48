/** @file */
#include <iostream>

#include "Wav.h"
#include "processor.h"
#include "normalization.h"

/**
 * \brief   The function bar.
 *
 * \details This function does something which is doing nothing. So this text
 *          is totally senseless and you really do not need to read this,
 *          because this text is basically saying nothing.
 *
 * \note    This text shall only show you, how such a \"note\" section
 *          is looking. There is nothing which really needs your notice,
 *          so you do not really need to read this section.
 *
 * \param[in]     a    Description of parameter a.
 * \param[out]    b    Description of the parameter b.
 * \param[in,out] c    Description of the parameter c.
 *
 * \return        The error return code of the function.
 *
 * \retval        ERR_SUCCESS    The function is successfully executed
 * \retval        ERR_FAILURE    An error occurred
 */
void fn(){

}

int main() {

    Wav wav;
    //wav.readFile("yes-16-bit-mono.wav");
    //wav.readFile("yes-26-bit-stereo.wav");
    wav.readFile("yes-8bit-mono.wav");
    IProcessor *processor = new Normalize(); 
    processor->processBuffer(wav.getBuffer(), wav.getBufferSize());

    //wav.readMeta("yes-8-bit-stereo.wav");

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
