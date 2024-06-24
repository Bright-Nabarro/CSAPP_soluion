$2MB / 512B = 4096$
$T_{max\_rotation} = 4ms$
$T_{avgrotation} = 2ms$

$T_{best\_transfer} = T_{max\_rotation} \cdot 4096/1000 = 16.384ms (all bolck)$
Best case have no ratation time.
$T_{best\_access} = 20.385ms$

$T_{random\_transfer} = T_{max\_rotation}/1000 = 0.004ms (1 block)$

$T_{random\_access} = 4096(T_{random\_transfer} + T_{avgseek} + T_{avgrotation}) = 24.6s $
