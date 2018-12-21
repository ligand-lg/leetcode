function ListNode(val) {
    this.val = val
    this.next = null
}

var addTwoNumbers = function (l1, l2) {
    var getNext = (l) => { return l ? l.next : null}
    var getValue = l => { return l ? l.val : 0 }
    var add = value_list => {
        let result = 0
        for (v of value_list) {
            result += v
        }
        return [result > 9 ? 1 : 0, result % 10]
    }
    let [carry, reminder] = add([l1.val, l2.val])
    const link_head = new ListNode(reminder)
    let result_pre_node = link_head,
        l1_cur_node = getNext(l1),
        l2_cur_node = getNext(l2)
    for (; l1_cur_node || l2_cur_node; l1_cur_node = getNext(l1_cur_node), l2_cur_node = getNext(l2_cur_node)) {
        [carry, reminder] = add([carry, getValue(l1_cur_node), getValue(l2_cur_node)])
        result_pre_node.next = new ListNode(reminder)
        result_pre_node = result_pre_node.next
    }
    if (carry !== 0) {
        result_pre_node.next = new ListNode(carry)
    }
    return link_head
};

var test = function () {
    const l1 = {
        val: 2,
        next: null
    }
    const l2 = {
        val: 5,
        next: {
            val: 6,
            next: {
                val: 4,
                next: null
            }
        }
    }
    let r = addTwoNumbers(l1, l2)
    while (r) {
        console.log(r.val+ '->')
        r = r.next
    }
}
test()