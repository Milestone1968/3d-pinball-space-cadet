#include "TDrain.h"

//----- (010172A3) --------------------------------------------------------
int __thiscall TDrain::Message(TDrain *this, int a2, float a3)
{
TDrain *v3; // esi

v3 = this;
if ( a2 == 1024 )
{
if ( *(_DWORD *)((char *)this + 86) )
{
timer_kill(*(_DWORD *)((char *)this + 86));
*(_DWORD *)((char *)v3 + 86) = 0;
}
*(_DWORD *)(*(_DWORD *)((char *)v3 + 30) + 78) = 0;
}
return 0;
}

//----- (010172D8) --------------------------------------------------------
void __stdcall TDrain::TimerCallback(int a1, struct TPinballComponent *a2)
{
control_handler(60, a2);
}

//----- (01018562) --------------------------------------------------------
void __thiscall TDrain::Collision(TDrain *this, struct TBall *a2, struct vector_type *a3, struct vector_type *a4, float a5, struct TEdgeSegment *a6)
{
TDrain *v6; // esi

v6 = this;
(**(void (__stdcall ***)(signed int, _DWORD))a2)(1024, 0.0);
*(_DWORD *)(*(_DWORD *)((char *)v6 + 30) + 78) = 1;
*(_DWORD *)((char *)v6 + 86) = timer_set(*(float *)((char *)v6 + 78), (int)v6, (int)TDrain::TimerCallback);
control_handler(63, v6);
}

//----- (0101A4B4) --------------------------------------------------------
TDrain *__thiscall TDrain::TDrain(TDrain *this, struct TPinballTable *a2, int a3)
{
TDrain *v3; // esi

v3 = this;
TCollisionComponent::TCollisionComponent(this, a2, a3, 1);
*(_DWORD *)((char *)v3 + 86) = 0;
*(_DWORD *)v3 = &TDrain::`vftable';
*(_DWORD *)((char *)v3 + 78) = *(_DWORD *)loader_query_float_attribute(a3, 0, 407);
return v3;
}
// 1002720: using guessed type void *TDrain::`vftable';
