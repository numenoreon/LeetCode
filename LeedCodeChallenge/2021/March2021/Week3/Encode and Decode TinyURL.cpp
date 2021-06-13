class Solution
{
public

stdstring encode(stdstring long_url) 
{   
    const stdstring a_hash = get_uuid();
    
    ma.insert({base + a_hash, long_url});
    cout  a_hash  endl;
    return a_hash;
}

stdstring decode(stdstring short_url) 
{
    return ma[base + short_url];
}

private

stdunordered_mapstring, string ma;

const stdstring base = httptinyurl.com;

const int sizeOfTineUrl = 5;

stdstring get_uuid() 
{
    static stdrandom_device dev;
    static stdmt19937 rng(dev());
    stduniform_int_distributionint dist(0, 15);

    const char v = 0123456789abcdef;

    stdstring res;

    for (int i = 0; i  sizeOfTineUrl; i++) 
    {
        res += v[dist(rng)];
    }

    return res;
}   
};