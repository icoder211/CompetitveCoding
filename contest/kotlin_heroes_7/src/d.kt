fun go4() {
    val n = readLine()!!.toInt()
    var b = IntArray(n)
    val a = readLine()!!.split(" ").map { it.toInt() }
    for(i in 0..n-1) {
        b[i] = a[i] // oof
    }
    b.sort()
    var ans : Long = 0
    var i=0
    while(i < n) {
        ans += b[i+1] - b[i]
        i+=2
    }
    println(ans)
}

fun main() {
    var t = 1
    while(--t >= 0) {
        go4()
    }
}