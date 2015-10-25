template<typename Iter, typename BinF, typename Res>
Res foldl (Iter first, Iter last, BinF func, Res seed)
{
	Iter next = first;
	next++;
	if(first == last) return seed;
	return foldl(next, last, func, func(*first, seed));
}
