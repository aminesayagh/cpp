Ce code utilise plusieurs concepts clés de la programmation orientée objet en C++ :
Classe
Une classe est un modèle pour créer des objets. Elle définit les données membres et les fonctions membres (appelées méthodes) qui peuvent être utilisées par ces objets. Dans ce code, la classe TableauTri est définie pour représenter un tableau trié d'éléments flottants.

Données membres
Les données membres sont des variables définies à l'intérieur d'une classe qui stockent des informations sur l'état de l'objet. Dans ce code, la classe TableauTri possède les données membres taille, tab et nbElis.

Fonctions membres
Les fonctions membres (ou méthodes) sont des fonctions définies à l'intérieur d'une classe qui permettent de manipuler les données membres de l'objet. Dans ce code, la classe TableauTri possède des méthodes telles que frequence(), supprimer(), operator+(), operator*(), etc.

Constructeurs
Les constructeurs sont des fonctions membres spéciales qui sont appelées lorsqu'un nouvel objet est créé. Ils permettent d'initialiser les données membres de l'objet. Dans ce code, il y a trois constructeurs différents : TableauTri(), TableauTri(int taille), TableauTri(const TableauTri &t). Chacun d'entre eux est appelé en fonction de la façon dont l'objet est créé.

Destructeur
Le destructeur est une fonction membre spéciale qui est appelée lorsqu'un objet est détruit. Il permet de libérer toutes les ressources utilisées par l'objet. Dans ce code, il existe un destructeur : ~TableauTri().

L'héritage est un concept permettant à une classe de dériver d'une autre classe existante. La classe dérivée (ou sous-classe) hérite des données membres et des fonctions membres de la classe de base (ou superclasse). Elle peut également définir de nouvelles données membres et de nouvelles fonctions membres. Dans ce code, la classe TableauTriResp est dérivée de la classe TableauTri. Elle hérite de toutes les données membres et fonctions membres de TableauTri, et ajoute également les données membres elementRepeter et elementNonRepeter.

Il est a noter que la classe TableauTriResp est une sous-classe de TableauTri, qui hérite de toutes les propriétés et méthodes de la classe de base, mais peut également définir des propriétés et des méthodes supplémentaires.

Encapsulation : L'encapsulation consiste à cacher les détails d'implémentation d'une classe derrière une interface publique. Cela permet aux utilisateurs de la classe de ne pas avoir à connaître les détails d'implémentation pour utiliser correctement la classe. Dans ce code, la classe TableauTri encapsule les détails de la manipulation du tableau trié en fournissant des fonctions publiques telles que frequence(), supprimer(), operator+(), etc. qui peuvent être utilisées pour manipuler le tableau, sans avoir besoin de connaître les détails de l'implémentation.

Abstraction : L'abstraction consiste à représenter un objet de manière à ne montrer que les informations pertinents et à cacher les détails non pertinents. Dans ce code, la classe TableauTri représente un tableau trié d'éléments flottants de manière abstraite, en fournissant des fonctions publiques pour manipuler le tableau sans montrer les détails de comment il est stocké en mémoire ou trié.

Polymorphisme : Le polymorphisme permet d'utiliser des objets de différentes classes de manière interchangeable, en faisant appel à leurs méthodes de la même manière. Dans ce code, l'opérateur operator<<() est utilisé de la même manière pour afficher les objets de la classe TableauTri et TableauTriResp, malgré le fait qu'ils soient de classes différentes.

Les fonctions friend:
Les fonctions friend sont des fonctions qui ont accès aux membres privés et protégés d'une classe même si elles ne sont pas membres de cette classe. Ce sont des fonctions qui ne font pas partie de la classe, mais qui ont un accès spécial à ses membres privés et protégés.

Dans ce code, les fonctions operator<<() et operator>>() sont déclarées comme friend de la classe TableauTri. Cela signifie qu'elles ont accès aux membres privés et protégés de TableauTri, comme les variables d'instance taille, tab et nbElis, même s'il ne sont pas membres de la classe TableauTri. Elles peuvent donc les utiliser pour afficher et saisir les éléments du tableau trié.

En utilisant les fonctions friend, il est possible d'accéder directement aux variables de classes privée ou protected qui ne sont normalement pas accessible depuis l'extérieur de la classe. Cependant, l'utilisation des fonctions friend doit être utilisé avec prudence car elle permet de contourner les principes de l'encapsulation et de l'abstraction qui favorisent la maintenance et l'évolution d'un code.

