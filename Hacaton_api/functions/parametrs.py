

from models.parametrs import Parametrs

from utils.pagination import pagination


def all_parametrs(search, id, from_date, end_date, page, limit, db, status):
    parametrs = db.query(Parametrs).filter(Parametrs.id >= 0)
    if search:
        parametrs = parametrs.filter(Parametrs.temperatura.like(search) |
                             Parametrs.wet.like(search) |
                             Parametrs.natural_gas.like(search) |
                             Parametrs.gas.like(search) |
                             Parametrs.dust1.like(search)|
                             Parametrs.dust2.like(search)|
                             Parametrs.dust3.like(search)|
                             Parametrs.lux.like(search))

    if id:
        parametrs = parametrs.filter(Parametrs.id == id)

    if from_date and end_date:
        parametrs = parametrs.filter(Parametrs.date >= from_date, Parametrs.date <= end_date)

    if status == True:
        parametrs = parametrs.filter(Parametrs.status == status)

    elif status == False:
       parametrs = parametrs.filter(Parametrs.status == status)

    else:
        parametrs = parametrs.filter(Parametrs.id >= 0)

    return pagination(form=parametrs, page=page, limit=limit)


def add_parametrs(form, db):
    new_parametr = Parametrs(temperatura=form.temperatura,
                     wet=form.wet,
                     natural_gas=form.natural_gas,
                     gas=form.gas,
                     dust1 = form.dust1,
                     dust2 = form.dust2,
                     dust3 = form.dust3,
                     lux = form.lux


                     )
    db.add(new_parametr)
    db.commit()
    db.refresh(new_parametr)

    return {"data": "User add base"}


def update_parametrs(id, form, db):
    db.query(Parametrs).filter(Parametrs.id == id).update({
        Parametrs.temperatura: form.temperatura,
        Parametrs.wet: form.wet,
        Parametrs.natural_gas: form.natural_gas,
        Parametrs.gas: form.gas,
        Parametrs.dust1: form.dust1,
        Parametrs.dust2: form.dust2,
        Parametrs.dust3: form.dust3,
        Parametrs.lux: form.lux,
        Parametrs.status: form.status,

    })
    db.commit()


def one_user(id, db):
    return db.query(Parametrs).filter(Parametrs.id == id).first()


def delete_parametrs(id, db):
    db.query(Parametrs).filter(Parametrs.id == id).update({
        Parametrs.status: False
    })

    db.commit()
    return {"data": "Malumot o'chirildi"}
