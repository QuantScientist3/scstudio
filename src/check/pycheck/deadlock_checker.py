from pysc import *

def referenced(h):
    if h.HMsc:
        # Initialization, step 1, h is in referenced(h)
        ref = [h]
    # Recursive part, over all the HMsc's that are (or will be) part of the referenced(h) and all its nodes, we're looking for their msc's and adding new HMsc's
    for k in ref:
        for n in k.nodes:
            if n.ReferenceNode and n.msc:
                msc = n.msc
                if msc.HMsc and msc not in ref:
                    ref.append(msc)
    return ref

def isBMscGraph(h):
    if h and h.HMsc and referenced(h) == [h]:
        return True
    else:
        return False

def traverse(n, l = []):
    # input is node n and optional list l (of already traversed nodes)
    if n and n.ReferenceNode and n.msc and n.msc.HMsc and n.msc.start not in l:
        # Found new HMsc in reference node, traversing
        l.append(n.msc.start)
        traverse(n.msc.start, l)
    for node in n.succ:
        if node and node not in l:
            l.append(node)
            traverse(node, l)
        else:
            # We don't want to end up in any cycle
            # pass is just an empty body/statement
            pass

def reachable(h, node):
    l = []
    # Lists are similar to pointers in C and can be changed inside of a function
    traverse(h.start, l)
    return node in l

def hasDeadlock(h):
    # Over all referenced HMsc's
    for hm in referenced(h):
        # Over all their nodes including start node
        for n in hm.snodes:
            if not n.ConnectionNode and not (n in h.nodes and n.EndNode):
                if reachable(h, n):
                    deadlock = True
                    for m in n.reachable:
                        if not m.ConnectionNode:
                            # We found reachable Node that is not ConnectionNode -> no deadlock
                            deadlock = False
                    if deadlock:
                        return n
    return None

def checkHMsc(h, chm):
    n = hasDeadlock(h)
    if n:
        print("Fail!")
        return [n.owner]
    print("Got pass")
    return []
