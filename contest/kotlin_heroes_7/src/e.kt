fun go5() {
    val n = readLine()!!.toInt()
    var b = IntArray(n)
    var sum : Long = 0
    val a = readLine()!!.split(" ").map { it.toInt() }
    for(i in 0 until n-1) {
        b[i] = a[i] // oof
        sum += b[i]
    }

    var ans = mutableListOf<Int>()
    for(i in 0 until n-1) {
        if(sum - b[i] == b[n-1].toLong()*2) {
            ans.add(i)
        }
    }
    if(sum - b[n-1] == b[n-2]*2.toLong()) ans.add(n-1)
    println(ans.size)
    for(i in 0 until ans.size) {
        print(b[ans[i].toInt()].toString()+" ")
    }
    println("")
}

fun main() {
    var t = 1
    while(--t >= 0) {
        go5()
    }
}