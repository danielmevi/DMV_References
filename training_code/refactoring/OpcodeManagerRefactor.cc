#include <any>
#include <iostream>
#include <memory>
#include <variant>

/////////////////////////////////////////////////////////////////////////////////////
enum Opcode { a, b, c, d, e };

struct Packet {
    Packet(const Opcode opcode) : opcode_(opcode) {}
    const Opcode opcode_;
};

void processOpcode(const Packet& packet) {
    const Opcode opcode = packet.opcode_;
    switch (opcode) {
        case a:
        case b:
            std::cout << "OpcodeAB: " << opcode << '\n';
            break;
        case c:
            std::cout << "OpcodeC: " << opcode << '\n';
            break;
        case d:
        case e:
            std::cout << "OpcodeDE: " << opcode << '\n';
            break;
        default:
            std::cout << "Unknown opcode\n";
    }
}

/////////////////////////////////////////////////////////////////////////////////////
// enum Opcode {a, b, c, d, e};

struct Packet1 {
    Packet1(const Opcode opcode) : opcode_(opcode) {}
    const Opcode opcode_;
};

void processAB(const Opcode opcode) {
    std::cout << "OpcodeAB: " << opcode << '\n';
}
void processDE(const Opcode opcode) {
    std::cout << "OpcodeCD: " << opcode << '\n';
}

// FILE process
void processA(const Opcode opcode) { processAB(opcode); }
void processB(const Opcode opcode) { processAB(opcode); }
void processC(const Opcode opcode) {
    std::cout << "OpcodeC: " << opcode << '\n';
}
void processD(const Opcode opcode) { processDE(opcode); }
void processE(const Opcode opcode) { processDE(opcode); }

void processOpcode1(const Packet1& packet) {
    const Opcode opcode = packet.opcode_;
    switch (opcode) {
        case a:
            processA(opcode);
            break;
        case b:
            processB(opcode);
            break;
        case c:
            processC(opcode);
            break;
        case d:
            processD(opcode);
            break;
        case e:
            processE(opcode);
            break;
        default:
            std::cout << "Unknown opcode\n";
    }
}

/////////////////////////////////////////////////////////////////////////////////////
// enum Opcode {a, b, c, d, e};

struct base_opcode {
    Opcode opcode_;
    explicit base_opcode(const Opcode opcode) : opcode_(opcode) {}
    virtual void processOpcode()
        const {};  // Cant be pure virtual because of std::any
};

struct OpcodeA : base_opcode {
    OpcodeA() : base_opcode(Opcode::a) {}
    virtual void processOpcode() const {
        std::cout << "OpcodeAB: " << opcode_ << '\n';
    }
};
struct OpcodeB : base_opcode {
    OpcodeB() : base_opcode(Opcode::a) {}
    virtual void processOpcode() const {
        std::cout << "OpcodeAB: " << opcode_ << '\n';
    }
};
struct OpcodeC : base_opcode {
    OpcodeC() : base_opcode(Opcode::a) {}
    virtual void processOpcode() const {
        std::cout << "OpcodeC: " << opcode_ << '\n';
    }
};
struct OpcodeD : base_opcode {
    OpcodeD() : base_opcode(Opcode::a) {}
    virtual void processOpcode() const {
        std::cout << "OpcodeCD: " << opcode_ << '\n';
    }
};
struct OpcodeE : base_opcode {
    OpcodeE() : base_opcode(Opcode::a) {}
    virtual void processOpcode() const {
        std::cout << "OpcodeCD: " << opcode_ << '\n';
    }
};

struct Packet2 {
    std::unique_ptr<base_opcode> opcode_ptr_;
    explicit Packet2(std::unique_ptr<base_opcode> opcode_ptr)
        : opcode_ptr_(std::move(opcode_ptr)) {}
};

void processOpcode2(const Packet2& packet) {
    packet.opcode_ptr_->processOpcode();
}

/////////////////////////////////////////////////////////////////////////////////////

struct Packet3 {
    const std::any opcode_;
    explicit Packet3(const std::any& opcode) : opcode_(opcode) {}
};

void processOpcode3(const Packet3& packet) {
    // TODO: make this work
    // std::any_cast<base_opcode>(packet.opcode_).processOpcode();
}

/////////////////////////////////////////////////////////////////////////////////////
// enum Opcode {a, b, c, d, e};

struct opcodeAB_tag {};
struct opcodeDE_tag {};

struct opcodeA_tag : opcodeAB_tag {};
struct opcodeB_tag : opcodeAB_tag {};
struct opcodeC_tag {};
struct opcodeD_tag : opcodeDE_tag {};
struct opcodeE_tag : opcodeDE_tag {};

struct Opcode_a {
    Opcode hex_ = Opcode::a;
    using opcode_type = opcodeA_tag;
};
struct Opcode_b {
    Opcode hex_ = Opcode::b;
    using opcode_type = opcodeB_tag;
};
struct Opcode_c {
    Opcode hex_ = Opcode::c;
    using opcode_type = opcodeC_tag;
};
struct Opcode_d {
    Opcode hex_ = Opcode::d;
    using opcode_type = opcodeD_tag;
};
struct Opcode_e {
    Opcode hex_ = Opcode::e;
    using opcode_type = opcodeE_tag;
};

template <class T>
void doProcessOpcode4(const T& opcode, opcodeAB_tag) {
    std::cout << "OpcodeAB: " << opcode.hex_ << '\n';
}
template <class T>
void doProcessOpcode4(const T& opcode, opcodeC_tag) {
    std::cout << "OpcodeC: " << opcode.hex_ << '\n';
}
template <class T>
void doProcessOpcode4(const T& opcode, opcodeDE_tag) {
    std::cout << "OpcodeDE: " << opcode.hex_ << '\n';
}

template <class T>
void parseProcessOpcode4(const T& opcode) {
    doProcessOpcode4(opcode, typename T::opcode_type());
}
template <class T>
void processOpcode4(const T& packet) {
    parseProcessOpcode4(packet.opcode_);
}

template <class T>
struct Packet4 {
    Packet4(const T& opcode) : opcode_(opcode) {}
    T opcode_;
};

/////////////////////////////////////////////////////////////////////////////////////

int main() {
    Packet P0{Opcode::a};
    processOpcode(P0);

    Packet1 P1{Opcode::a};
    processOpcode1(P1);

    Packet2 P2(std::make_unique<OpcodeA>());
    processOpcode2(P2);

    Packet3 P3{OpcodeA()};
    processOpcode3(P3);

    Packet4 P4{Opcode_a()};
    processOpcode4(P4);
}
