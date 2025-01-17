# 操作系统

## 操作系统0001 操作系统的概念（定义）
操作系统（Operating System，简称 OS）是控制和管理整个计算机系统的硬件和软件资源，并合理地组织调度计算机的工作和资源分配，以提供给用户和其他软件方便的接口和环境。它是计算机系统中最基本的系统软件。
具体来说，操作系统承担以下几个主要角色：
1.系统资源的管理者：操作系统负责管理计算机系统的硬件和软件资源，包括处理器、内存、存储设备、网络等，以确保它们有效、安全地被应用程序使用。
2.向上提供方便易用的服务：操作系统通过各种用户界面和服务接口，使用户和应用程序能够方便地访问和操作计算机系统，屏蔽底层硬件细节，提供高层抽象。
3.最接近硬件的一层软件：操作系统直接与计算机的硬件交互，负责管理和控制硬件资源的访问和使用，为上层应用程序提供必要的执行环境和资源分配。

## 操作系统0002 操作系统的目标——作为系统资源的管理者
操作系统的主要目标之一是作为系统资源的管理者。它提供以下功能：处理机管理、存储器管理、文件管理和设备管理。其核心目标是确保系统的安全性和高效性。


## 操作系统0003 操作系统的目标——向上层提供方便易用的服务
操作系统的主要目标之一是向上层提供方便易用的服务。它采用封装的思想，将一些复杂的硬件功能封装成简单易用的服务，使用户能更方便地使用计算机。用户无需关心底层硬件的原理，只需要对操作系统发出命令即可。
向上层提供的这些服务分为两类：直接给用户使用的服务和给软件或程序员使用的服务。直接给用户使用的服务包括图形用户界面（G U I）和命令接口。命令接口又分为联机命令接口和脱机命令接口。联机命令接口是用户说一句，系统做一句；脱机命令接口则是用户说一堆，系统做一堆。
给软件或程序员使用的服务主要是程序接口，即系统调用。用户通过程序接口间接使用操作系统提供的服务。

## 操作系统0004 操作系统的目标——作为最接近硬件的层次
操作系统的目标之一是在裸机基础上提供资源管理和用户服务功能，使其更加强大和方便使用。裸机指没有任何软件支持的计算机。通过安装操作系统，裸机可以转变为扩充功能和使用更便捷的机器，也称为虚拟机或扩充机器。操作系统作为最接近硬件的层次，需要实现对硬件机器的有效拓展。

## 操作系统0005 操作系统的特征
操作系统具有几个重要的特征：
首先，它是并发和共享的。并发意味着操作系统能够同时处理多个任务，而共享则包括互斥共享方式（例如摄像头设备的共享使用）和同时共享方式（例如硬盘资源的共享使用）。这两个特征是操作系统最基本的特征，彼此互为存在条件。
其次，操作系统是虚拟的。它使用空分复用技术（例如虚拟存储器技术）和时分复用技术（例如虚拟处理器），使得多个用户和应用程序能够共享有限的硬件资源，同时获得良好的使用体验。
最后，操作系统是异步的，即各种事件的发生和处理是不可预测的，操作系统需要及时响应和处理这些事件。
这些特征共同定义了操作系统的基本属性和功能。

## 操作系统0006 并发
并发是指在同一时间间隔内发生两个或多个事件。这些事件在宏观上看似同时发生，但在微观上是交替发生的。常常容易混淆的概念是并行，并行是指两个或多个事件在同一时刻同时发生。
操作系统的并发性意味着计算机系统中有多个程序在“同时”运行，这些程序在宏观上看是同时运行的，但在微观上是交替运行的。操作系统是伴随着“多道程序技术”而出现的，因此，操作系统和程序并发是一起诞生的。
需要注意的是，单核CPU在同一时刻只能执行一个程序，各个程序只能并发地执行；而多核CPU在同一时刻可以同时执行多个程序，多个程序可以并行地执行。

## 操作系统0007 共享
共享即资源共享，系统中的资源可以供内存中多个并发执行的进程共同使用。
在操作系统中，共享资源的方式主要有两种：
1.互斥共享方式：某些资源虽然可以供多个进程使用，但在任意时间段内，只允许一个进程访问该资源。这种方式通过互斥机制来实现，保证在同一时刻只有一个进程可以操作该资源，从而避免数据的不一致性和竞态条件。
2.同时共享方式：某些资源允许多个进程在同一时间段内同时访问。在宏观上看，多个进程可以同时操作该资源，但在微观上，这些进程可能会交替地对资源进行访问（即分时共享）。这种方式通常需要操作系统提供合适的调度和同步机制，以确保各个进程对资源的公平访问和正确性。

## 操作系统0008  并发和共享的关系
并发和共享是计算机系统中密切相关的概念。并发性指的是系统中同时存在多个运行着的程序，这些程序可以在同一时刻执行不同的任务或操作。共享性则是指系统中的资源（如内存、文件、设备等）可以被多个并发执行的进程共同使用。
这两者是互为存在条件的：如果没有并发性，即系统只能同时运行一个程序，那么共享性就失去了意义，因为资源不需要被多个进程共享。反之，如果失去了共享性，即资源不能被多个进程共同使用，系统的资源利用效率可能会降低，因为每个进程可能需要独占一份资源，导致资源浪费和性能下降。
因此，并发性和共享性相辅相成，是确保计算机系统能够高效运行的重要条件之一。

## 操作系统0009 虚拟
虚拟是指将一个物理实体转换为若干个逻辑上对应的实体。物理实体即其实际存在的形式，而逻辑上对应的实体则是用户可以感知和操作的形式。
虚拟技术可分为不同类型：
1.空分复用技术，例如虚拟存储器技术；
2.时分复用技术，例如虚拟处理器。
显然，如果系统失去了并发性，即在一个时间段内只能运行一个程序，那么实现虚拟性的意义也将丧失。因此，没有并发性，虚拟性也就无从谈起。

## 操作系统0010 异步
异步指的是在多道程序环境下，允许多个程序并发执行。由于资源有限，进程的执行并不是一直连续不断的，而是可能会出现走走停停的情况，以不可预测的速度向前推进，这就是进程的异步性。只有当系统具有并发性时，才有可能出现进程的异步执行。

## 操作系统0011 操作系统的发展与分类
操作系统的发展与分类可以概括为几个阶段和类型：
首先是手工操作阶段，这一阶段的操作系统依赖人工手动控制和管理。
其次是批处理阶段，包括单道批处理系统和多道批处理系统。单道批处理系统一次只能处理一个作业，而多道批处理系统则允许同时处理多个作业，这标志着操作系统的初步出现。
随后是分时操作系统，这种系统能够使多个用户同时与计算机交互，实现分时共享计算机资源的方式。
在此基础上发展出实时操作系统，专门用于处理对时间要求极高的任务，例如工业控制和航空航天领域。
随着网络技术的进步，出现了网络操作系统，这种操作系统专注于支持分布在网络上的多台计算机之间的协作和通信。
最后是分布式操作系统，它管理分布在多台计算机上的资源和任务，旨在提高整个系统的性能和可靠性。
除了以上主要类型，还有个人计算机操作系统，专门设计用于个人电脑的操作系统，如Windows、MacOS和Linux等。
这些阶段和类型反映了操作系统在不同应用场景和需求下的演进和多样化发展。

## 操作系统0012 手工操作阶段
手工操作阶段存在几个主要缺点：首先是用户独占全机，这意味着在操作过程中，机器或设备只能由一个用户独占使用，无法同时处理多个任务或者多个用户的需求。其次是人机速矛盾，即人类操作员的速度和机器设备的响应速度不匹配，导致操作效率低下。这种情况下，机器的资源利用率极低，效率难以得到充分提升。

## 操作系统0013 单道批处理系统
单道批处理系统引入了脱机输入/输出技术，即通过外围设备和磁带来完成输入和输出操作，由监督程序（操作系统的初级形态）控制作业的执行过程。
其主要优点在于缓解了人机速度矛盾的问题，同时提升了资源利用率。
然而，这种系统也存在一些显著的缺点。首先，内存中只能容纳一道程序在运行，其他程序必须等待当前程序执行结束才能被调入。这导致CPU大量的时间被空闲浪费在等待输入/输出操作完成上，资源利用率并没有得到显著提升，依然较低。

## 操作系统0014 多道批处理系统
多道批处理系统是操作系统的一种形式，旨在支持多个程序并发执行。每次将多个程序加载到内存中，使得计算机能够在一段时间内轮流执行它们。这种系统的主要优点在于能够实现多道程序的并发执行，从而共享计算机资源。这样一来，CPU和其他资源可以保持高效利用，系统整体的吞吐量得以增大。
然而，多道批处理系统也存在一些显著的缺点。首先，由于程序是批量提交的，用户的响应时间较长。一旦用户提交了作业，就只能等待计算机处理完成，期间无法对作业进行调试或输入额外的参数。这种缺乏人机交互的特性限制了用户在程序执行过程中的控制能力，例如无法实时调整程序的执行或输入运行时的指令。
总体而言，多道批处理系统通过提高资源利用率和系统吞吐量，为当时的计算环境带来了显著的优势，但同时也牺牲了用户对程序执行过程的直接控制和交互功能。

## 操作系统0015 分时操作系统
分时操作系统是一种计算机操作系统，其工作原理是按照时间片轮流为各个用户或作业提供服务。每个用户通过终端与计算机进行交互，操作系统将计算资源分配给各个用户，使它们可以独立地使用计算机，而彼此之间感受不到其他用户的存在。
其主要优点在于能够即时响应用户请求，有效解决了人机交互的问题。此外，分时操作系统允许多个用户同时使用一台计算机，而它们的操作是相互独立的，每个用户可以按照自己的需求和步调进行操作。
然而，分时操作系统也有其主要缺点。它不能优先处理一些紧急任务，因为操作系统对各个用户或作业是公平的，每个用户都会按照时间片轮流获得服务，而不考虑任务的紧急性或重要性。这意味着即使某些任务需要立即完成，也必须等待其轮到被处理。
总结来说，分时操作系统通过时间片轮转的方式实现多用户共享计算资源，解决了人机交互的需求，但无法针对任务的紧急性进行优先处理。

## 操作系统0016 实时操作系统
实时操作系统具有显著的优势，主要在于能够优先响应紧急任务，并且某些紧急任务无需等待时间片轮转。在这类操作系统的控制下，计算机系统能够即时处理外部信号，并在严格的时间限制内完成任务。实时操作系统的特点主要体现在及时性和可靠性方面。
实时操作系统分为硬实时操作系统和软实时操作系统两种类型。硬实时操作系统必须在绝对严格的预定时间内完成任务，例如导弹控制系统和自动驾驶系统。而软实时操作系统则能够偶尔违反规定，例如12306火车订票系统。
这些系统设计的目标是确保在各种情况下都能在预期的时间内完成任务，以满足特定的时间限制要求。

## 操作系统0017 其他操作系统
其他操作系统：
网络操作系统是随着计算机网络的发展而诞生的，能够将网络中的各个计算机有机地结合起来，实现数据传送等功能，以及实现网络中各种资源的共享，例如文件共享，和各台计算机之间的通信。典型的例子是Windows NT，它被广泛用于网站服务器等场景。
分布式操作系统的主要特点是分布性和并行性。在这种系统中，各台计算机地位相同，任何任务都可以分布在这些计算机上，并由它们并行协同完成。这种设计使得分布式操作系统能够高效地处理大规模的计算和数据处理任务。
个人计算机操作系统，例如Windows XP和MacOS，旨在方便个人使用。这些操作系统提供了图形用户界面和各种应用程序，使得个人用户能够轻松地管理文件、运行程序和进行日常工作。

## 操作系统0018 操作系统的运行机制
操作系统的运行机制包括两种指令类型：特权指令和非特权指令。特权指令用于系统资源的管理，只能在核心态执行；非特权指令则用于一般的数据处理，可以在用户态和核心态执行。
操作系统维护两种处理器状态：核心态和用户态。核心态下操作系统具有对系统资源的完全控制权限，而用户态下则受到限制，只能执行非特权指令和有限的系统资源访问。
操作系统由两种程序组成：内核程序和应用程序。内核程序管理系统的核心功能和资源，如进程和内存管理；应用程序则由用户直接使用，通过操作系统提供的服务和接口运行。
这些要素共同作用，构成了操作系统的基本运行机制。

## 操作系统0019 内核程序VS应用程序
内核程序和应用程序在计算机系统中扮演着不同的角色和功能：
应用程序是为了完成特定任务而设计和编写的软件程序，通常由最终用户直接使用。用户通过应用程序来完成各种工作，例如处理文档、播放媒体、浏览网页等。应用程序运行在操作系统之上，利用操作系统提供的服务和资源来执行任务。
内核程序则是构成操作系统核心部分的软件程序。操作系统内核由多个内核程序组成，负责管理和协调系统的各种硬件和软件资源。内核程序是操作系统最核心、最重要的部分，也是最接近硬件的层次。它提供给应用程序访问硬件资源的接口，并负责调度任务、管理内存、处理中断和异常等核心操作。
总结来说，应用程序是为用户提供特定功能的软件，而内核程序则是操作系统的核心组成部分，负责管理和控制计算机系统的硬件资源，以及提供给应用程序访问这些资源的接口。

## 操作系统0020 特权指令VS非特权指令
特权指令与非特权指令在处理器（CPU）中执行时有明显的区别。所谓的“指令”是处理器能够识别和执行的最基本命令。特权指令需要特殊权限才能执行，通常由操作系统内核处理。这些指令用于访问系统资源或执行特殊的机器级操作。相反，非特权指令无需特殊权限即可由应用程序执行，如算术运算或逻辑运算。
处理器在设计和制造过程中就已经划分了特权指令和非特权指令，因此在执行任何指令之前，处理器都能够准确地识别并区分它们的类型。

## 操作系统0021 内核态、用户态的切换
内核态和用户态的切换过程。
当从内核态切换到用户态时，需要执行一条特权指令——这条指令会修改PSW的标志位为“用户态”。这个动作意味着操作系统将主动让出CPU的使用权。
而从用户态切换到内核态则是由“中断”引发的。硬件会自动完成这个切换过程，触发中断信号意味着操作系统将强行夺回CPU的使用权。
除了非法使用特权指令之外，还有很多事件也会触发中断信号。一个共同点是，只要需要操作系统介入的地方，都会触发中断信号。

## 操作系统0022 中断的作用
“中断”在操作系统中起着重要作用，它是操作系统内核夺回CPU使用权的唯一途径。当系统发生中断时，CPU会从用户态转变为内核态，这使得操作系统能重新夺回对CPU的控制权。

## 操作系统0023 中断的类型
中断可以分为两大类型：内中断和外中断。
内中断，也称为异常或例外，具体又分为三类：陷阱、故障和终止。陷阱是由陷入指令引发的，是应用程序故意引发的；故障是由错误条件引起的，可能被内核程序修复；终止则是由致命错误引起的，内核程序无法修复该错误。
外中断，也称为中断，主要包括时钟中断和I/O中断请求。

## 操作系统0024 内中断
内中断是与当前执行的指令有关的中断信号，来源于CPU内部。当当前执行的指令是非法的，CPU就会发出一个中断信号。例如，试图在用户态下执行特权指令，或者执行除法指令时发现除数为0。除此之外，CPU有时也会主动发出内中断。例如，有时候应用程序需要请求操作系统内核的服务，此时会执行一条特殊的指令——陷入指令，这会引发一个内部中断信号。需要注意的是，陷入指令不是特权指令。

## 操作系统0025 外中断
外中断与当前执行的指令无关，而是由CPU外部发出的中断信号。例如，时钟中断是由时钟部件发送的信号，用于定期更新系统时间；而I/O中断则是由输入/输出设备发送的信号，用于通知CPU有数据传输或设备状态变化需处理。这些外部中断能够打断CPU当前的执行流程，使其暂时转向处理中断服务程序，以响应外部事件或设备请求。


## 操作系统0026 中断机制的基本原理
不同的中断信号，需要用不同的中断处理程序来处理。当CPU检测到中断信号后，会根据中断信号的类型去查询“中断向量表”，以此来找到相应的中断处理程序在内存中的存放位置。

## 操作系统0027 系统各层级之间与系统调用和库函数的关系
系统各层级之间与系统调用和库函数的关系：
普通应用程序可以直接进行系统调用，也可以使用库函数来实现功能。库函数有的直接实现功能而不涉及系统调用，有的则会涉及到系统调用来完成特定任务。
在编程语言层级，通常会提供库函数来简化程序员的开发工作。有时，编程语言会将常用的系统调用封装成库函数，这样可以隐藏系统调用的实现细节，使得编程更加方便和跨平台。
操作系统层级向上提供系统调用接口，使得应用程序能够通过系统调用请求操作系统内核提供的各种服务和功能。
至于裸机层级，通常指没有操作系统支持的硬件环境，此时程序直接与硬件进行交互而无法使用操作系统提供的系统调用或库函数。
这些层级之间的关系决定了程序员在不同开发环境下如何利用系统调用和库函数来实现各种应用程序的功能需求。

## 操作系统0027 系统调用简介
系统调用简介：
操作系统作为用户和计算机硬件之间的接口，扮演着提供简单易用服务的角色。它通过命令接口和程序接口向上层提供服务，其中程序接口由一组系统调用构成。
系统调用是操作系统提供给应用程序使用的接口，类似于特殊函数，应用程序可以通过系统调用请求操作系统内核提供的服务。

## 操作系统0028 系统调用VS库函数——系统调用
系统调用VS库函数之系统调用的相关概念：
一、系统调用是操作系统提供给用户空间程序与操作系统内核间交互的接口。
二、它们通常提供了对底层硬件资源（如文件系统、网络、进程管理等）的访问。
三、系统调用由操作系统内核实现和维护，而且执行系统调用会导致用户空间程序的特权级别从用户态切换到内核态。

## 操作系统0029 系统调用VS库函数——库函数
库函数是由程序员编写的可虫用代码块，通常存储在动态链接库（DLL）或静态链接库（静态库）中。它们提供了一系列常用功能的实现，为程序员提供了更高层次的抽象和更方便的编程接口。库函数通常在用户空间运行，而且不需要特权级别的切换。
例如，printf()、scanf()、strlen()、memcpy()等都是C语言标准库中的函数，它们提供了输入输出、字符串长度计算、内存拷贝等常见操作的实现。这些函数调用不会直接操作操作系统的底层资源，而是通过标准库的封装提供了高层次的接口，使得程序员可以更方便地进行编程。

## 操作系统0030 系统调用VS库函数——区别总结
系统调用和库函数的区别如下：
系统调用提供了对操作系统功能的直接访问，而库函数则封装和抽象了常用功能。系统调用的执行需要切换特权级别，而库函数通常在用户空间执行。系统调用的功能更为底层，而库函数的功能则更为高层。
在实际编程中，通常建议尽可能使用库函数，因为它们提供了更高的抽象和可移植性，并且能够隐藏底层实现的细节，使编程更加简单和可维护。然而，有时需要直接访问操作系统提供的底层功能，这时就需要使用系统调用。

## 操作系统0031 系统调用的必须性
系统调用的必须性包括：
访问受限资源、提供安全保障、实现进程间通信和提供系统服务。

## 操作系统0032 系统调用的必须性：访问受限资源
访问受限资源是操作系统中的一个关键概念。操作系统管理着计算机的底层资源，包括硬件设备、文件系统和网络等。用户程序要想对这些资源进行操作，必须通过系统调用向操作系统请求服务。比如，打开文件、读取网络数据或者创建新进程等操作，都必须通过系统调用来完成。这种设计保证了资源的安全性和可控性，防止用户程序直接访问或破坏核心资源，同时允许操作系统对资源进行有效的管理和调度。

## 操作系统0033 系统调用的必须性：提供安全保障
系统调用的必要性之：提供安全保障；
系统调用提供了安全保障。操作系统通过系统调用管理对系统资源的访问，确保不同程序之间的隔离和安全性。系统调用限制了用户程序对系统资源的直接访问，防止恶意程序破坏或滥用系统资源。

## 操作系统0034 系统调用的必须性：实现进程间通信
系统调用的必要性之一是实现进程间通信。在多进程或多线程的环境中，不同的进程或线程需要进行通信和协作。操作系统提供了各种机制来支持进程间通信，如管道、消息队列、共享内存等，而这些机制通常需要通过系统调用来完成。

## 操作系统0035 系统调用的必须性：提供系统服务
系统调用的必要性之一是提供系统服务。操作系统通过系统调用为用户程序提供各种系统服务，例如内存管理、进程调度和文件系统管理等。这些服务为用户程序提供了基础设施，使得用户程序可以更方便地实现各种功能。

## 操作系统0036 系统调用的必须性总结
系统调用是用户程序与操作系统之间的关键接口。它们是实现程序功能、访问系统资源以及保障系统安全的必要手段。没有系统调用，用户程序将无法有效地访问系统资源或与操作系统进行交互，从而无法完成各种任务。

## 操作系统0037 调用系统调用的时机
应用程序通过系统调用请求操作系统的服务。在操作系统中，各种共享资源由内核统一管理。因此，所有涉及共享资源的操作，比如存储分配、I/O操作、文件管理等，都需要通过系统调用向操作系统内核发出服务请求，由内核代为完成。这种方式确保了系统的稳定性和安全性，有效防止用户进行非法操作。

## 操作系统0038 系统调用的分类
系统调用按功能分类如下：
一、设备管理：完成设备的请求、释放、启动等功能；
二、文件管理：完成文件的读、写、创建、删除等功能；
三、进程控制：完成进程的创建、撤销、阻塞、唤醒等功能；
四、进程通信：完成进程之间的消息传递、信号传递等功能；
五、内存管理：完成内存的分配、回收等功能。

## 操作系统0039 系统调用的过程
系统调用的过程如下：
用户程序发起系统调用请求，先传递参数然后执行陷入指令。这一过程将用户程序从用户态切换至内核态，以便内核可以访问系统资源。接着，内核执行系统调用服务例程，根据系统调用号确定具体的服务例程。执行完毕后，返回结果给用户程序，返回值存储在特定的寄存器中。最后，内核将控制权切换回用户态，用户程序可以继续执行其后续的指令。

## 操作系统0040 系统调用的过程：用户程序发起系统调用请求
系统调用的第一步是用户程序发起系统调用请求。这通常通过调用特定的系统调用函数或执行陷入指令来完成。陷入指令是一种特殊的指令，其作用是将程序的执行权转移给操作系统内核。
在发起系统调用请求之前，用户程序必须准备好系统调用所需的所有参数。这些参数可以包括函数参数、系统调用号等信息。系统调用号通常用于标识要执行的特定系统调用功能，而函数参数则包含了系统调用所需的具体数据和选项。
因此，用户程序在发起系统调用请求时，需要确保所有参数都被正确设置和传递，以确保系统能够正确地执行所请求的操作。

## 操作系统0041 系统调用的过程：切换至内核态
用户程序发起系统调用请求时，处理器必须执行一系列步骤来切换当前执行上下文，从用户态切换至内核态，以便操作系统内核能够处理这一请求。这种切换涉及特权级别的转换，即从用户程序运行在较低特权级别的用户态切换至操作系统内核运行在较高特权级别的内核态，从而使内核能够安全地访问和控制系统资源。
切换至内核态是系统调用过程中的关键步骤，它通过特权级别的转换确保了操作系统内核对系统资源的有效管理和保护。

## 操作系统0042 系统调用的过程：执行系统调用服务例程
系统调用的过程之：执行系统调用服务例程。当处理器处于内核态时，操作系统内核会根据系统调用号确定需要执行的系统调用服务例程。系统调用服务例程是操作系统内核中实现特定系统调用功能的代码段。操作系统内核会根据系统调用请求中的参数执行相应的操作，例如打开文件、读取数据等。

## 操作系统0043 系统调用的过程：返回结果给用户程序
系统调用服务例程执行完毕后，操作系统内核将系统调用的结果返回给用户程序。通常情况下，返回值存储在特定的寄存器中，以便用户程序可以通过适当的方式获取。

## 操作系统0044 系统调用的过程：切换回用户态
系统调用的过程之切换回用户态：
当系统调用服务例程执行完毕，并且结果已经返回给用户程序后，处理器会执行上下文从内核态切换回用户态，使得用户程序可以继续执行其后续的指令。

## 操作系统0045 系统调用的过程：总结
系统调用的过程可以总结如下：
系统调用的过程涉及以下几个关键步骤：首先，用户程序传递系统调用参数；接着，系统执行陷入指令，将控制从用户态切换到核心态；然后，在核心态下执行相应的内核程序来处理系统调用；最后，处理完成后返回结果给应用程序。这一过程是操作系统向用户程序提供服务的重要机制之一。

## 操作系统0046 系统调用的过程：注意
系统调用的过程中需要注意以下几点：
一、陷入指令在用户态执行，执行该指令会立即触发一个内中断，将CPU从用户态切换到核心态。
二、系统调用请求由用户态发起，而对系统调用的处理则在核心态进行。
三、请注意以下同义词：陷入指令等于trap指令，等于访管指令。

## 操作系统0047 操作系统体系结构
操作系统体系结构有几种主要类型：
首先是大内核，又称为宏内核或单内核，其特点是将操作系统的大部分功能集成在一个单一的内核中。
其次是微内核，这种架构将操作系统的核心功能尽可能地精简，将其余功能以服务的形式运行在核心之外。
还有分层结构，它将操作系统分为多个层次，每一层次负责不同的功能，通常按照抽象程度从低到高排列。
另一种是模块化架构，操作系统的功能被组织为多个相互独立的模块，每个模块可以独立开发、测试和更新。
最后是外核，这是一种较新的架构概念，尝试通过在不同的抽象层次上组织和管理操作系统的功能，以提高系统的可扩展性和灵活性。

## 操作系统0048 操作系统的内核
操作系统内核包括两个主要功能模块：
1.与硬件关联较紧密的模块包括：时钟管理；中断处理； 原语；
2.对系统资源进行管理的功能包括：进程管理；存储器管理；设备管理；

## 操作系统0049 操作系统的内核
操作系统的内核是操作系统最基本、最核心的部分。它由一组程序组成，负责实现和管理操作系统的核心功能。内核程序是指那些直接实现操作系统基本功能的程序，包括任务调度、内存管理、文件系统管理等。

## 操作系统0050 时钟管理&中断处理
时钟管理利用时钟中断进行计时，确保操作系统能够准确追踪时间。中断处理则负责响应外部设备和内部事件的请求，保证系统稳定运行。

## 操作系统0051 原语
原语是一种特殊的程序，具有原子性，即操作要么全部执行，要么都不执行，执行期间不可中断。它位于操作系统的最底层，是最接近硬件的部分。原语的特点之一是运行时间较短，并且经常被频繁调用。

## 操作系统0052 微内核VS大内核
在讨论操作系统内核架构时，主要有两种类型：大内核和微内核。
首先是大内核，它将操作系统的主要功能模块都作为系统内核，运行在核心态。大内核的优点是高性能。然而，大内核的缺点也很明显。其一，内核代码庞大，结构混乱，难以维护。其二，大内核中的某个功能模块出错，就可能导致整个系统崩溃。
接下来是微内核。微内核只把最基本的功能保留在内核中。微内核的优点包括内核功能少，结构清晰，方便维护。同时，内核外的某个功能模块出错不会导致整个系统崩溃。不过，微内核也存在缺点。由于需要频繁地在核心态和用户态之间切换，性能较低。此外，用户态下的各功能模块不可以直接相互调用，只能通过内核的消息传递来间接通信。

## 操作系统0053 微内核VS大内核
微内核与大内核在操作系统设计中有着显著的区别。微内核将操作系统的核心功能模块化，大部分系统服务和功能实现为用户空间的进程或服务。这种架构通过微内核提供的通信机制来实现模块间的交互，因而涉及相对频繁的CPU状态切换。
相反，大内核设计则倾向于将核心功能尽可能集成在内核中，使得这些功能在内核态直接运行，从而提高系统的整体性能。由于大部分功能在内核态运行，这种设计导致相对较少的CPU状态切换。
需要注意的是，CPU状态的切换是有一定成本的，因为它需要消耗时间。频繁地进行状态切换会降低系统的性能，因此在选择操作系统设计架构时，需权衡这些因素。

## 操作系统0054 分层结构
操作系统结构之：分层结构。
特性和思想：内核分为多层，最底层是硬件，最高层是用户接口。每一层可以单向调用更低一层提供的接口。
优点包括便于调试和验证，可以自底向上逐层进行调试和验证。扩充和维护也较为容易，因为各层之间调用的接口清晰且固定。
缺点是只能调用相邻的低层，难以合理定义各层的边界。效率低下，不能跨层调用，系统调用的执行时间较长。

## 操作系统0055 模块化结构

操作系统内核结构之模块化结构，这种设计将内核划分为主模块和可加载内核模块，并鼓励各模块之间进行协作。主模块专注于核心功能，如进程调度和内存管理；而可加载内核模块则允许动态添加新功能，而无需重新编译整个内核。
这种结构有几个显著的优点。首先，模块间的逻辑清晰，易于维护，只要确定了模块间的接口，就可以并行开发多个模块。其次，支持动态加载新的内核模块，例如安装设备驱动程序或者引入新的文件系统模块，从而增强操作系统的适应性。此外，模块之间可以直接调用，而无需采用消息传递机制，因此效率较高。
然而，这种模块化结构也存在一些缺点。例如，模块间的接口定义可能不合理或不实用，导致系统设计的复杂性。另外，模块之间可能会出现相互依赖，这增加了调试和验证的难度。

## 操作系统0056 外核结构
外核结构的特性和思想在于分离内核和外核的功能，以实现更灵活和高效的硬件资源管理。内核主要负责进程调度和通信等核心功能，而外核则负责直接分配未经抽象的硬件资源给用户进程，并确保其安全使用。
其优点在于，外核能够直接为用户进程分配未经虚拟化和抽象化的硬件资源，使得用户进程可以更灵活地利用这些资源，同时减少了虚拟硬件资源映射层，从而提升了系统的效率。
然而，外核结构也存在一些缺点，例如降低了系统的一致性，因为内核和外核分离可能导致系统状态管理变得更为复杂，使系统整体的维护和调试变得更加困难。

## 操作系统0057 一个安装了操作系统的磁盘内部结构
磁盘的内部结构可以分为几个关键部分。首先是主引导记录，简称M B R，它包含了磁盘引导程序和分区表。磁盘引导程序负责引导启动过程，而分区表则记录了磁盘上所有分区的信息。
接着是C盘，它包含引导记录P B R，负责引导操作系统的加载；根目录，用于存储文件系统中所有文件和目录的索引；以及其他相关信息。
除了C盘之外，还有其他的盘符，它们也包含类似的结构，但具体内容会根据各自的用途和设置而有所不同。


## 操作系统0058 操作系统引导（开机过程）
操作系统引导过程（即，开机过程）。
一、C P U从一个特定主存地址开始，取指令，执行R O M中的引导程序(先进行硬件自检，再开机)；
二、将磁盘的第一块主引导记录读入内存，执行磁盘引导程序，扫描分区表；
三、从活动分区(又称主分区，即安装了操作系统的分区)读入分区引导记录，执行其中的程序；
四、从根目录下找到完整的操作系统初始化程序（即启动管理器）并执行，完成“开机”的一系列动作；

## 操作系统0059 虚拟机
虚拟机是通过虚拟化技术将一台物理机器虚拟化为多台虚拟机的系统。每台虚拟机可以独立运行一个操作系统。
同义的术语包括虚拟机管理程序（Virtual Machine Monitor, VMM）、虚拟机监控程序（Hypervisor）

## 操作系统0060 虚拟机的分类

虚拟机可分为两类，第一类V M M直接运行在硬件上  ；第二类V M M运行在宿主操作系统上。

在对物理资源的控制权上，第一类虚拟机直接运行在硬件之上，能直接控制和分配物理资源；第二类虚拟机则运行在主机操作系统之上，依赖于主机操作系统为其分配物理资源。

在资源分配方式上，第一类虚拟机在安装虚拟客户操作系统时，虚拟机管理程序要在原本的硬盘上自行分配存储空间，类似于外核的分配方式，分配未经抽象的物理硬件。第二类虚拟机的虚拟客户操作系统拥有自己的虚拟磁盘，该盘实际上是主机操作系统文件系统中的一个大文件。虚拟客户操作系统分配到的内存是虚拟内存。

在性能上，第一类虚拟机的性能更好。第二类虚拟机的性能更差，因为其需要主机操作系统作为“中介”。

在可支持的虚拟机数量上，第一类虚拟机可以支持更多的虚拟机，因为不需要和主机操作系统竞争资源，相同的硬件资源可以支持更多的虚拟机。第二类虚拟机可以支持的数量较少，因为主机操作系统本身需要使用物理资源，主机操作系统上运行的其他进程也需要物理资源。

在虚拟机的可迁移性上，第一类虚拟机的可迁移性较差。第二类虚拟机的可迁移性更好，只需导出虚拟机镜像文件即可迁移到另一台主机操作系统上，因此商业化应用更广泛。

在运行模式上，第一类虚拟机管理程序运行在最高特权（Ring 0）等级下，可以执行最高特权的指令。第二类虚拟机管理程序部分运行在用户态、部分运行在内核态。虚拟客户操作系统发出的系统调用会被虚拟机管理程序截获，并转化为虚拟机管理程序对主机操作系统的系统调用。

## 操作系统0061 进程的概念
程序是静态的，它只是一个存放在磁盘上的可执行文件，简单来说，就是一系列指令的集合。而进程则是动态的，是程序的一次执行过程。同一个程序多次执行，会对应多个进程。

## 操作系统0062 进程的组成

进程由几个主要组成部分构成：

首先是PCB（进程控制块），它包含着进程的描述信息、进程的控制和管理信息、资源分配清单以及处理机相关信息。

其次是程序段，包括程序的代码（指令序列），描述了进程执行的操作和指令流程。

最后是数据段，存放运行过程中产生的各种数据，例如程序中定义的变量和其他数据。

这些组成部分共同定义了一个进程的结构和运行时所需的资源。

## 操作系统0063 进程的组成
一个进程的组成部分包括进程控制块（P C B）、程序段和数据段。P C B是供操作系统使用的，而程序段和数据段是供进程自身使用的。进程是动态的，而进程实体（或进程映像）是静态的。
在引入进程实体的概念后，进程可以定义为：进程是进程实体的运行过程，是系统进行资源分配和调度的一个独立单位。当一个进程被“调度”时，意味着操作系统决定让这个进程在CPU上运行。

## 操作系统0064 PCB
进程控制块，简称PCB，包含几个重要部分。
首先是进程描述信息，包括进程标识符PID和用户标识符UID。接下来是进程控制和管理信息，这部分内容涵盖了CPU、磁盘、网络流量的使用情况统计以及进程当前状态，比如就绪态、阻塞态、运行态等。
另外还有资源分配清单，列出进程正在使用的文件、内存区域以及I/O设备。最后是处理机相关信息，例如P S W、P C等各种寄存器的值，这些信息用于实现进程切换。

## 操作系统0065 进程控制块PCB
进程控制块（PCB）

PCB是进程存在的唯一标志。当操作系统创建进程时，会为每个进程创建一个对应的PCB。当进程结束时，系统会回收其对应的PCB。

在进程创建时，操作系统会分配一个唯一且不重复的进程ID（PID），这可以看作是进程的“身份证号”。

PCB包含了操作系统对进程管理所需的所有信息。它记录了进程的当前状态、程序计数器、内存分配情况、调度信息、打开文件列表以及其他与进程相关的信息。操作系统通过访问和更新PCB来管理各个并发运行的进程。

## 操作系统0066 程序段、数据段
程序段包含程序指令，而数据段则包含运行过程中产生的各种数据。

## 操作系统0067 进程的特征
程序是静态的，而进程是动态的。相比于程序，进程具有以下特征：
首先是动态性，这是进程最基本的特征。进程是程序的一次执行过程，是动态地产生、变化和消亡的。
其次是并发性。在内存中有多个进程实体，各进程可以并发执行。
然后是独立性。进程能够独立运行，独立获得资源，独立接受调度，是基本单位。
还有异步性。各进程按各自独立的、不可预知的速度向前推进，操作系统需要提供进程同步机制来解决异步问题。
最后是结构性。每个进程都会配置一个P C B。从结构上看，进程由程序段、数据段和P C B组成。

## 操作系统0068 进程的状态
进程有几种状态，主要包括三种基本状态和两种其他状态。三种基本状态是运行状态、就绪状态和阻塞状态。此外，还有创建状态和终止状态。

## 操作系统0069 创建态、就绪态
当进程正在被创建时，它的状态是“创建态”。在这个阶段，操作系统会为进程分配资源并初始化PCB。进程创建完成后，它会进入“就绪态”。处于就绪态的进程已经具备运行条件，但由于没有空闲的CPU，暂时不能运行。

## 操作系统0070 运行态
当一个进程正在CPU上运行时，这个进程被称为处于‘运行态’。此时，CPU会执行该进程对应的程序，也就是执行相应的指令序列。

## 操作系统0071 阻塞态
在进程运行过程中，可能会请求等待某个事件的发生，比如等待某种系统资源的分配，或者等待其他进程的响应。在这个事件发生之前，进程无法继续执行，此时操作系统会让这个进程退出CPU，并进入“阻塞态”。

## 操作系统0072 终止态
一个进程可以通过执行exit系统调用，请求操作系统终止它自己。这时候，该进程会进入“终止态”，操作系统会从CPU中移除该进程，并且回收它所占用的内存空间以及其他资源。最后，操作系统还会释放该进程的PCB（即，进程控制块），以便将其重新用于其他目的或者释放相应的系统资源。

## 操作系统0073 进程状态间的转换
进程状态之间的转换包括以下几种情况：
首先是从创建态到就绪态，这意味着系统完成了创建进程的一系列工作。
接下来，从就绪态到运行态，这表示进程被调度开始执行。
然后是从运行态到就绪态，这通常发生在时间片到期，或者处理器被其他高优先级进程抢占时。
从运行态到阻塞态，这是进程自身主动做出的行为。通常是进程通过系统调用申请某种系统资源，或者请求等待某个事件发生。
再者，从阻塞态到就绪态，这不是进程自身能控制的，而是一种被动行为。一般是由于申请的资源已经被分配，或者等待的事件已经发生。
最后，从运行态到终止态，这表示进程运行结束，或者在运行过程中遇到了不可修复的错误。

## 操作系统0074 进程状态间的转换_补充
在讨论进程状态间的转换时，需要注意两点。首先，进程不能由阻塞态直接转换为运行态，也不能由就绪态直接转换为阻塞态。这是因为进入阻塞态是进程主动请求的动作，必然需要在进程运行时才能发出这种请求。在单CPU情况下，同一时刻只会有一个进程处于运行态；而在多核CPU情况下，可能会有多个进程同时处于运行态。
在进程的整个生命周期中，大部分时间都会处于三种基本状态：运行态、就绪态和阻塞态。值得注意的是，阻塞态也被称为等待态；创建态被称为新建态；终止态被称为结束态。
在进程的PCB（进程控制块）中，会有一个变量叫做state，用来表示进程的当前状态。例如，1表示创建态，2表示就绪态，3表示运行态。为了便于对同一个状态下的各个进程进行统一管理，操作系统会将这些进程的PCB组织起来，这就是进程的组织方式。

## 操作系统0075 进程的组织方式
进程的组织方式可以通过两种主要方法来实现：
一、链接方式：按照进程状态将PCB（进程控制块）分为多个队列，操作系统持有指向各个队列的指针。
二、索引方式：根据进程状态的不同，建立几张索引表，操作系统持有指向各个索引表的指针。
这两种方式分别通过队列和索引表的方式，有效地管理和组织系统中的进程。

## 操作系统0076 链接方式
链接方式指的是在操作系统中管理进程的一种方法。每个进程控制块（P C B）都包含一个指向下一个进程控制块的指针，这些PCB形成一个链表结构。当操作系统需要管理一个新的进程时，会创建一个对应的P C B，并将其链接到链表的末尾或适当位置。
通过这种链表结构，可以通过遍历链表来管理和访问所有的进程。这种方式相对比较简单，特别适用于进程数量较少且不需要频繁进行快速访问的情况。

## 操作系统0077 索引方式
索引方式是一种用于管理大量进程的方法。系统维护一个进程表，每个进程都有一个唯一的索引号，这个索引号允许系统快速访问特定的进程。与传统的链表或者数组方式不同，索引方式通过直接根据索引号定位进程控制块（PCB），避免了需要遍历整个数据结构的操作。因此，它特别适用于需要频繁进行快速访问和操作的场景。