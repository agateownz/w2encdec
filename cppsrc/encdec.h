#ifndef __ENC_DEC_HPP__
#define __ENC_DEC_HPP__

#include <cstdint>
#include <cstdlib>

class W2EncDec
{
private:
    W2EncDec(/* args */);
    virtual ~W2EncDec() {}
    W2EncDec(const W2EncDec &) = delete;
    W2EncDec &operator=(const W2EncDec &) = delete;

public:
    static bool Decode(uint8_t *buffer, int32_t offset, int32_t length);
    static bool Encode(uint8_t *buffer, int32_t offset, int32_t length);
};

#endif // !__ENC_DEC_HPP__