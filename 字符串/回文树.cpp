const int MAXN = 400005 ;
const int CN = 26 ;
struct Palindromic_Tree {
    int nxt[MAXN][CN] ;//nxt指针，nxt指针和字典树类似，指向的串为当前串两端加上同一个字符构成
    int fail[MAXN] ;//fail指针，失配后跳转到fail指针指向的节点
    int cnt[MAXN] ;//cnt[i]表示节点i表示的本质不同的串的个数（建树时求出的不是完全的，最后count()函数跑一遍以后才是正确的）
    int num[MAXN] ;//num[i]表示以节点i表示的最长回文串的最右端点为回文串结尾的回文串个数
    int len[MAXN] ;//len[i]表示节点i表示的回文串的长度
    int s[MAXN] ;//存放添加的字符
    int last ;//指向上一个字符所在的节点，方便下一次add
    int n ;//字符数组指针
    int p ;//节点指针

    int newnode ( int l ) {//新建节点
        for ( int i = 0 ; i < CN ; ++ i ) nxt[p][i] = 0 ;
        cnt[p] = 0 ;
        num[p] = 0 ;
        len[p] = l ;
        return p ++ ;
    }

    void init () {//初始化
        p = 0 ;
        newnode (  0 ) ;
        newnode ( -1 ) ;
        last = 0 ;
        n = 0 ;
        s[n] = -1 ;//开头放一个字符集中没有的字符，减少特判
        fail[0] = 1 ;
    }

    int get_fail ( int x ) {//和KMP一样，失配后找一个尽量最长的
        while ( s[n - len[x] - 1] != s[n] ) x = fail[x] ;
        return x ;
    }

    void add ( int c ) {
        c -= 'a' ;
        s[++ n] = c ;
        int cur = get_fail ( last ) ;//通过上一个回文串找这个回文串的匹配位置
        if ( !nxt[cur][c] ) {//如果这个回文串没有出现过，说明出现了一个新的本质不同的回文串
            int now = newnode ( len[cur] + 2 ) ;//新建节点
            fail[now] = nxt[get_fail ( fail[cur] )][c] ;//和AC自动机一样建立fail指针，以便失配后跳转
            nxt[cur][c] = now ;
            num[now] = num[fail[now]] + 1 ;
        }
        last = nxt[cur][c] ;
        cnt[last] ++ ;
    }

    void count () {
        for ( int i = p - 1 ; i >= 0 ; -- i ) 
            cnt[fail[i]] += cnt[i] ;
        
        //父亲累加儿子的cnt，因为如果fail[v]=u，则u一定是v的子回文串！
    }

}G;